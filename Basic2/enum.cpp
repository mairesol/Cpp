// #include <iostream>
// using namespace std;

// EXAMPLE 1: Thong tin san pham
// enum ItemTypes
// {
//     LAPTOP,
//     DESKTOP,
//     MOBILE,
//     NETWORK
// };

// void showAllLaptop()
// {
//     cout << "Laptop Information\n";
// }

// void showAllDesktop()
// {
//     cout << "Desktop Information\n";
// }

// void showAllMobile()
// {
//     cout << "Mobile Information\n";
// }

// void showAllNetworkItem()
// {
//     cout << "Network Item Information\n";
// }

// void showProducts(ItemTypes type)
// {

//     switch (type)
//     {
//     case LAPTOP:
//         showAllLaptop();
//         break;

//     case DESKTOP:
//         showAllDesktop();
//         break;

//     case MOBILE:
//         showAllMobile();
//         break;

//     case NETWORK:
//         showAllNetworkItem();
//         break;

//     default:
//         break;
//     }
// }

// EXAMPLE 2: Trang thai cua boss
// enum BossState
// {
// 	IDLING,
// 	RUNNING,
// 	JUMPING,
// 	DYING
// };

// BossState state;

// void initBoss()
// {
// 	//init something
// 	state = IDLING;
// }

// void attack()
// {
// 	//............
// }

// void activated()
// {
// 	//............
// }

// void updateAnimation(BossState state)
// {
// 	switch(state)
// 	{
// 	case IDLING:
// 		standStill();
// 		break;

// 	case RUNNING:
// 		setRunningAnimation();
// 		break;

// 	case JUMPING:
// 		setJumpingAnimation();
// 		break;

// 	case DYING:
// 		setDyingAnimation();
// 		break;

// 	default;
// 		break;
// 	}
// }

// EXAMPLE 3: Ma loi
// enum ReturnValue
// {
// 	SUCCESS = 0,
// 	INITIALIZE_ERROR = -1,
// 	LOAD_RESOURCE_ERROR = -2,
// 	RUN_TIME_ERROR = -3
// };

int main()
{
    // example 1
    //     ItemTypes type = MOBILE;
    //     showProducts(type);

    // example 3
    // if (initialize() == false) {
    // 	return INITIALIZE_ERROR;
    // }

    // if (loadResource() == false) {
    // 	return LOAD_RESOURCE_ERROR;
    // }

    // bool isRunning = true;
    // while (isRunning) {

    // 	//Application event loop
    // 	return RUN_TIME_ERROR;
    // }

    // return SUCCESS;

    return 0;
}