if [[ $1 != 'ONE' ]]
	then
	clang++ -Wall -Wextra -Werror -std=c++98 main_test.cpp -D mine -D uncolored -o ft; ./ft > mine_diff
	clang++ -Wall -Wextra -Werror -std=c++98 main_test.cpp -D uncolored -o std; ./std > std_diff
else
	clang++ -Wall -Wextra -Werror -std=c++98 main_test.cpp -D mine -o ft; ./ft > mine_diff
	clang++ -Wall -Wextra -Werror -std=c++98 main_test.cpp -o std; ./std > std_diff
fi

diff mine_diff std_diff > result.diff

res=$( cat result.diff )
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
NC='\033[0m'

if [[ -z $res ]]
	then
	echo "${GREEN}Everything work - No Difference${NC}"
	rm -rf mine_diff std_diff result.diff test_results/
else
	echo "${RED}Some Differences Appears! ${YELLOW}Check them in: ${NC}./test_results/"
	rm -rf test_results/
	cat result.diff
	mkdir test_results
	mv mine_diff std_diff result.diff test_results/
fi

if [ -z $1 ] || [ $1 != 'ONE' ]
	then
	rm ft
	rm std
fi