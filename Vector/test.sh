g++ -Wall -Wextra -Werror -std=c++98 main_test.cpp -D mine -D uncolored; ./a.out > mine_diff
g++ -Wall -Wextra -Werror -std=c++98 main_test.cpp -D uncolored; ./a.out > std_diff

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
rm a.out
