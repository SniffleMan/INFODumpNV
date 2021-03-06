#ifndef	INFODUMPNV_VERSION_INCLUDED
#define INFODUMPNV_VERSION_INCLUDED

#define MAKE_STR_HELPER(x) #x
#define MAKE_STR(x) MAKE_STR_HELPER(x)

#define INFODUMPNV_VERSION_MAJOR	1
#define INFODUMPNV_VERSION_MINOR	0
#define INFODUMPNV_VERSION_PATCH	0
#define INFODUMPNV_VERSION_BETA		0
#define INFODUMPNV_VERSION_VERSTRING	MAKE_STR(INFODUMPNV_VERSION_MAJOR) "." MAKE_STR(INFODUMPNV_VERSION_MINOR) "." MAKE_STR(INFODUMPNV_VERSION_PATCH) "." MAKE_STR(INFODUMPNV_VERSION_BETA)

#endif
