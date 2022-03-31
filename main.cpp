#include <iostream>


#include "funcs.h"

int main()
{
  std::cout << "==============START TESTS===============\n";
  // std::cout << encryptCaesar("Bpm ycqks jzwev nwf rcuxml wdmz bpm tihg lwo" ,17) << "\n";
  std::cout << "solve(\"Ftq cguow ndaiz raj vgybe ahqd ftq xmlk pas.\") returns:\n" << solve("Ftq cguow ndaiz raj vgybe ahqd ftq xmlk pas.") << "\n\n";
  std::cout << "solve(\"Pwti. ¿Kwuw mabia? Mabwg jqmv. ¿G bc?\") returns:\n" << solve("Pwti. ¿Kwuw mabia? Mabwg jqmv. ¿G bc?") << "\n\n";
  std::cout << "solve(\"ymci ko hsbyw uo ww rsgi mc bs\") returns:\n" << solve("ymci ko hsbyw uo ww rsgi mc bs") << "\n\n";
  std::cout << "solve(\"rj yz edv odib ncd ucjib bpj mzi ov hzi yjib edvib ucjib rzi\") returns:\n" << solve("rj yz edv odib ncd ucjib bpj mzi ov hzi yjib edvib ucjib rzi") << "\n\n";
  std::cout << "solve(\"Qrhgfpur Jhefgr fvaq qvr fpuyvzzfgra!\") returns:\n" << solve("Qrhgfpur Jhefgr fvaq qvr fpuyvzzfgra!") << "\n";
  std::cout << "================END TESTS===============\n";
  return 0;
}
