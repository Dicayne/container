clang++ -Wall -Wextra -Werror -std=c++98 main_speed.cpp -D mine -o ft_speed
clang++ -Wall -Wextra -Werror -std=c++98 main_speed.cpp -o std_speed

RED='\033[0;31m'
CYAN='\033[1;34m'
YELLOW='\033[0;33m'
NC='\033[0m'

echo "${CYAN}This test take approximatly 1min\n${NC}"

echo "${YELLOW}Time of ft:${NC}\ntime ./ft_speed\n"
time ./ft_speed

echo "-----------------------------------\n${YELLOW}Time of std:${NC}\ntime ./std_speed\n"
time ./std_speed

echo "\n${CYAN}COMPARE REAL TIME.${NC}"

rm ft_speed
rm std_speed