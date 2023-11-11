#ifndef IMAGES_H
#define IMAGES_H

namespace asciiImages
{
  enum ImageEnum
  {
    none = 0,
    fighter = 1,
    mage,
    Choose,
    mageAnimation,
    candleAnimation,
    fighterAnimation,
    manWalkingSun,
    manPickingFromTree,
    elephant,
    worm,
    blobMonster,
    skull,
    ghost,
    skeleton,
    palmTree,
    bag
  };
}

namespace images
{
  const char *none = R"( )";
  const char *fighterStatic = R"(

|==(W{==========-       
    ||  (.--.)         
    | \_,|**|,__      
    `\ ' `--'   ),     
      `\_. .__/\ \`      
        | .  |~~\~|    
       /==0==-\  /    
      /~\___/~~\/    

    )";
  const char *manWalkingSun = R"(                            .-""""-.
                           F       `Y
                          F          Y
                          L          J          ##
                           L        J          ###
                       #    `-.__.-'          ####
              _____   ##                 .---#####-...__
          .--'     `-###          .--..-'    ######     ""`--- 
 _____.----.        ###`.._____ .'          #######
 a:f                ###       /       -.    ####### _.---
                    ##      : `--...        ######
                     #       `.     ``.     ######
                           _   :       :.    #####
                          ( )            )    ###
                         ,- -.           /    ##
                        |,   .|          |   .##
                        || ' |;         |     '
                     .  ((_, J         <
                   .'    | | |         |
                  /      | ; )         |
                 '       |_ -          .
)";
  const char *manPickingFromTree = R"(             .-__
          .-'   )`-__
          )          \.-.
       .-.-.             )
      /                  \
     |                   /
     \                   (
     |              _    /
     (       -.      \__/C
      \        \       ( |:
       ) U\    |       / || _
       `'  `-._| .-._.'  \ ( )
               | >        \  \
              -< |        )   \
               | |        \  (\\ _____________
               | |        |  ) `|             |
               | |        | /   =             =
               | |        | \   |             |
 a:f_________.-' "-______-'  \__|             |________________________)";
  const char *elephant = R"(                              
 
 [-----]
 
)";
  const char *skull = R"( 
              _______________
         /               \
        /                 \
       /                   \
       |    /\       /\   /
       |   (  )     (  )  |
       |    ``       ``   |,
       |         M         |
        \__     DDD     __/
         |\     XXX     /|
         | |           | |
         |     |```|     |
         |     \___/     |
          \            _/
           \_         _/
             \_______/

  )";
  const char *ghost = R"( 
    ./```````\.
   ./          \.
 (               )
 |  (^)    (^)    |
 |                |
|                |
|      MMM       |
|     MMMMM       |
|     MMMMM       |
 |     MM        |
 (_______________)

  )";

  const char *skeleton = R"( 
T        T
[========]  j
 \ `*  * /  | 
  |  `  |   |
   \ & /`  s@s
    \ /    /
|--Q||D---/ 
|  \||/
|   ||     
)";
  const char *blobMonser = R"( 
    _____T.. .-___T
  ,/========/--\=======\
 /     ,,               \
 \    \*O/    `O*,      \
  `i        -V-          i
   i ;              ,    i
   ;    /`v```v`\        `.
   ;   <         >        ;..
  ;     \,^,,^,,/   ;     ;\..
 /;\  /                 ;;;\..
 /,;\_____________,.,.,/.,/\... 
)";
  const char *worm = R"( 
  _/*****\_
L/         \J
 \ `S`  `S`/
  \  /`\  /               i
   | \,/ |                |
    \     \    /```````\  |
     \     \../    _    \//
      |           /  \   /
       \........./    \./  

   
)";

  const char *bag = R"(
   __     ___
  //\\   // ;\
 /`````````````]\\
(;             )}/
(;___       ___)}
(;   \__@__/   )}
(;             )}
 \`            )}       
  `=..====..==//
)";
  const char *palmTree = R"( 
        __ _.--..--._ _
     .-' _/   _/\_   \_'-.
    |__ /   _/\__/\_   \__|
       |___/\_\__/  \___|
              \__/
              \__/
               \__/
                \__/
             ____\__/___
       . - '             ' -.
      /                      \
~~~~~~~  ~~~~~ ~~~~~  ~~~ ~~~  ~~~~~
  ~~~   ~~~~~   ~!~~   ~~ ~  ~ ~ ~pjb   
)";

}

#endif