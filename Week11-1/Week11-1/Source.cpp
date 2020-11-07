#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
using namespace std;
struct A {
	string name;
	int price=0;
};
A a[1000],ans[1000];
int collectOrder(int cnt) {
	int j=0, k=0;
	int ch = 0;
	scanf(" %d %d", &j, &k);
	if (j == -1 && k == -1) {
		return 0;
	}
	else if (k <= 0) {
		printf("Invalid Amount\n");
		return 1;
	}
	else if (j >0 && k > 0) {
		if (j > 3) {
			printf("Error 404 : No menu found\n");
			return 1;
		}
		for (int i = 0;i < cnt;i++) {
			if (a[j-1].name==ans[i].name) {
				ans[i].price += a[j-1].price * k;
				ch = 1;
				break;
			}
			else if(a[j-1].name != ans[i].name && ch == 0 && i == cnt-1){
				ans[cnt].name = a[j-1].name;
				ans[cnt].price += a[j-1].price * k;
			}
		}
		return 1;
	}
}
int main() {
	int m=0,ansPrice=0;
	char type='\0', yn='\0';
	a[0].name = "Fried Chicken";
	a[0].price = 20;
	a[1].name = "Sticky Rice";
	a[1].price = 10;
	a[2].name = "Soda";
	a[2].price = 10;
	printf("----------------Today's Menu---------------\n");
	for (int i = 0; i < 3;i++) {
		cout << "No." << i + 1 << ": " << a[i].name << " " << a[i].price<<" Bath"<<endl;
	}
	printf("-------------------------------------------\n");
	printf("Type E to Eat here or type T to take away : ");
	scanf(" %c", &type);
	if (type == 'T') {
		printf("Do your want plastic cutlery this will cost you 10 Bath (type Y for yes or N for no) : ");
		scanf(" %c", &yn);
		if (yn == 'Y') {
			ansPrice += 10;
		}
		else if (yn != 'Y' && yn != 'N') {
			printf("Error Try Again\n");
			return 0;
		}
	}
	else if (type != 'T' && type != 'E') {
		printf("Error Try Again\n");
		return 0;
	}
	printf("Start your order now and if you're done type -1 -1\n");
	printf("Input your order in \"No. Amount\" format\n"); 
	int cnt = 1;
	while (cnt) {
		if (!collectOrder(cnt)) {
			break;
		}
		else 
			cnt++;
	}
	printf("Your order is :\n");
	for (int i = 0;i < cnt;i++) {
		if(ans[i].price != 0)
			cout << ans[i].name << " " << ans[i].price << " Bath" << endl;
 		ansPrice += ans[i].price;
	}
	if (yn == 'Y') printf("Plastic Cutlery 10 Bath\n");
	if (type == 'T') printf("Take Away\n");
	else if (type == 'E') printf("Eat Here\n");
	printf("----------------Net Amount----------------\n%d Bath",ansPrice);
	return 0;
}