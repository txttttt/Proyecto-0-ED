#include <string>
#include "OrderedArrayList.h"
#include "KVPair.h"
#include "Header.h"

using std::string;

int main() {
	List<KVPair<int, string>>* users = new OrderedArrayList<KVPair<int, string>>(10);
	List<KVPair<int, string>>* services = new OrderedArrayList<KVPair<int, string>>(10);
	runningLoop(&getMenuAction);
	return 0;
}