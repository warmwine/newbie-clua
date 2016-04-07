#include <string.h>

#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"

struct Student
{
	char *strName;
	char *strNum;
	int iSex;
	int iAge;
};

static int CreateStudent(lua_State *L)
{
	size_t studentSize = sizeof(struct Student);
	struct Student *pStudent;
	pStudent = (struct Student *)lua_newuserdata(L, studentSize);

	return 1;
}

static int GetName(lua_State *L)
{
	struct Student *pStudent = (struct Student *)lua_touserdata(L, 1);
	luaL_argcheck(L, pStudent != NULL, 1, "Wrong Parameter");
	lua_pushstring(L, pStudent->strName);
	return 1;
}

static int SetName(lua_State *L)
{
	struct Student *pStudent = (struct Student *)lua_touserdata(L, 1);
	luaL_argcheck(L, pStudent != NULL, 1, "Wrong Parameter");

	const char *pName = luaL_checkstring(L, 2);
	luaL_argcheck(L, pName != NULL && pName != "", 2, "Wrong Parameter");
	pStudent->strName = pName;
	return 0;
}
