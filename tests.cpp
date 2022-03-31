#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("Testing solve function")
{
    CHECK(solve("Ftq cguow ndaiz raj vgybe ahqd ftq xmlk pas.") == "The quick brown fox jumps over the lazy dog.");
    CHECK(solve("Pwti. ¿Kwuw mabia? Mabwg jqmv. ¿G bc?") == "Hola. ¿Como estas? Estoy bien. ¿Y tu?");
    CHECK(solve("ymci ko hsbyw uo ww rsgi mc bs") == "kyou wa tenki ga ii desu yo ne");
    CHECK(solve("rj yz edv odib ncd ucjib bpj mzi ov hzi yjib edvib ucjib rzi") == "wo de jia ting shi zhong guo ren ta men dong jiang zhong wen");
    CHECK(solve("Qrhgfpur Jhefgr fvaq qvr fpuyvzzfgra!") == "Deutsche Wurste sind die schlimmsten!");
}
