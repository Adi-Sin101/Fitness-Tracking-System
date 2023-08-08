#include <iostream>
#include <cmath>

using namespace std;

class UserProfileManager {
private:
    string name;
    int age;
    double weight;
    double height;

public:
    // Constructor with arguments
        UserProfileManager( string name, int age, double weight, double height)
        : name(name), age(age), weight(weight), height(height) {}

    // Default constructor
    UserProfileManager()
        : name("None"), age(-1), weight(0.0), height(0.0) {}

    // Getter functions
    string getName() { return name; }
    int getAge()  { return age; }
    double getWeight() { return weight; }
    double getHeight() { return height; }

    // Display user information
    void displayUserInfo() {
        cout << "User Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Height: " << height << " meter" << endl;
    }

    // Update user information
    void updateUserInfo( string newName, int newAge, double newWeight, double newHeight)
    {
        name = newName;
        age = newAge;
        weight = newWeight;
        height = newHeight;
         //cin.ignore(); // Clear the newline character left in the buffer

    }

    // Delete user information
    void deleteUserInfo() {
        name = "";
        age = 0;
        weight = 0.0;
        height = 0.0;
    }

    friend void BMI_Calculator( UserProfileManager &person);
};

class Food_Calory {
public:
    int roti = 92;    // per rotii
    int egg = 74;     // per egg
    int rice = 350;   // per plate
    int mutton = 250;   // 100 grams// per bowl
    int lentils = 116;// 100 grams // per cup
    int banana = 110; // 1 banana
    int apple = 95;   // 1 apple
    int milk = 42;    // 100 grams //per cup
    int pizza = 285;  // 1 slice
    int soup = 76;    // 1 cup
    int shawarma = 800; // 1 piece

    //(Add more food items and their respective calorie counts if needed)
};

class Meal {
private:
    int roti;
    int egg;
    int rice;
    int mutton;
    int lentils;
    int banana;
    int apple;
    int milk;
    int pizza;
    int soup;
    int shawarma;

public:
    Meal()
     {
         roti=0; egg=0; rice=0; mutton=0; lentils=0; banana=0; apple=0;milk=0; pizza=0; soup=0; shawarma=0;

     }

    void setMealIntake() {
    int option;
    char choice;
    cout << "Do you want to update meal intake? (Y/N): ";
    cin >> choice;

    while (choice == 'Y' || choice == 'y') {
        cout << "Choose an option to update food intake:" << endl;
        cout << "1. Rotii (per roti)" << endl;
        cout << "2. Egg (per egg)" << endl;
        cout << "3. Rice (per plate)" << endl;
        cout << "4. Mutton (per bowl)" << endl;
        cout << "5. Lentils (per cup)" << endl;
        cout << "6. Banana (1 banana)" << endl;
        cout << "7. Apple (1 apple)" << endl;
        cout << "8. Milk (100 grams per cup)" << endl;
        cout << "9. Pizza (1 slice)" << endl;
        cout << "10. Soup (1 cup)" << endl;
        cout << "11. Shawarmaa (1 piece)" << endl;

        cout << "Enter the option (1, 2, 3, etc.): ";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter the number of Roti taken: ";
                cin >> roti;
                break;
            case 2:
                cout << "Enter the number of Egg taken: ";
                cin >> egg;
                break;
            case 3:
                cout << "Enter the number of Rice taken per plate: ";
                cin >> rice;
                break;
            case 4:
                cout << "Enter the number of Mutton taken per bowl: ";
                cin >> mutton;
                break;
            case 5:
                cout << "Enter the number of Lentils taken per cup: ";
                cin >> lentils;
                break;
            case 6:
                cout << "Enter the number of Banana taken: ";
                cin >> banana;
                break;
            case 7:
                cout << "Enter the number of Apple taken: ";
                cin >> apple;
                break;
            case 8:
                cout << "Enter the amount of Milk taken in grams (per cup): ";
                cin >> milk;
                break;
            case 9:
                cout << "Enter the number of Pizza slices taken: ";
                cin >> pizza;
                break;
            case 10:
                cout << "Enter the amount of Soup taken in cups: ";
                cin >> soup;
                break;
            case 11:
                cout << "Enter the number of Shawarmaa pieces taken: ";
                cin >> shawarma;
                break;
            default:
                cout << "Invalid option selected." << endl;
                break;
        }

        cout << "Do you want to update more food intake? (Y/N): ";
        cin >> choice;
    }
}

    long int calculateCalorieIntake(const Food_Calory& food) const {
        long int totalCalories = roti * food.roti +
                                 egg * food.egg +
                                 rice * food.rice +
                                 mutton * food.mutton +
                                 lentils * food.lentils +
                                 banana * food.banana +
                                 apple * food.apple +
                                 milk * food.milk +
                                 pizza * food.pizza +
                                 soup * food.soup +
                                 shawarma * food.shawarma;
        return totalCalories;
    }
};


void BMI_Calculator( UserProfileManager &person)
{
    float bmi = person.weight / pow(person.height, 2);
    cout << person.getName() << "'s BMI is: " << bmi << endl;

    if (bmi < 18.5)
        cout << "You are underweight" << endl;
    else if (bmi >= 18.5 && bmi <= 24.9)
        cout << "Your weight is normal" << endl;
    else if (bmi >= 25 && bmi <= 29.9)
        cout << "You are overweight" << endl;
    else if (bmi >= 30 && bmi <= 34.9)
        cout << "You are suffering from obesity (Class 1)" << endl;
    else if (bmi >= 35 && bmi <= 39.9)
        cout << "You are suffering from obesity (Class 2)" << endl;
    else
        cout << "You are suffering from extreme obesity (Class 3)" << endl;
}

long int balance_calory(long int totalCalories)
{
        int gender;
    cout << "Enter your Gender: ";
    cout << "Choose an option:" << endl;
    cout<<"0 for selecting male"<<endl;
    cout<<"1 for selecting female"<<endl;
    cin>>gender;

    if (gender == 0) {
        if (totalCalories > 2500) {
            cout << "You have to burn " << (totalCalories - 2500) << " calories" << endl;
            return (totalCalories-2500);
        } else if (totalCalories < 2500) {
            cout << "You have to gain " << (2500 - totalCalories) << " calories" << endl;
            return (totalCalories-2500);
        } else {
            cout << "You are a healthy male" << endl;
            return 0;
        }
    } else if (gender == 1) {
        if (totalCalories > 2000) {
            cout << "You have to burn " << (totalCalories - 2000) << " calories" << endl;
            return (totalCalories-2000);
        } else if (totalCalories < 2000) {
            cout << "You have to gain " << (2000 - totalCalories) << " calories" << endl;
            return (totalCalories-2000);
        } else {
            cout << "You are a healthy female" << endl;
            return 0;
        }
    } else {
        cout << "Invalid gender selection." << endl;
        return 0;
    }

}
class Exercise_name {
private:
    int running = 12;    //1 min=12 calories
    int pushup = 20; // 1 push-ups = 20 calories
    int squats = 20; // 1 squat = 20 calories
    int plank = 10;       // 10 calories per minute

public:
    friend void exercise_choice(Exercise_name &E, long int balance);
};

void exercise_choice(Exercise_name &E, long int balance) {
    if (balance > 0) {
        float run_exercise = ((3.0 / 4) * balance ); // 3/4 of the exercise through running
        float remaining_calories = balance - run_exercise;

        if (run_exercise > 0) {
            int run_time = run_exercise /E.running; // 30 minutes in 360 calories

            cout << "You need to run for " << run_time<< " minutes to burn " << run_exercise<< " calories" << endl;
        }

        if (remaining_calories > 0) {
                float per_exercise=remaining_calories/3;
            int pushup_time = per_exercise/ E.pushup;
            int squat_time = per_exercise/ E.squats;
            int plank_time = per_exercise/ E.plank;

            cout << "You need to also do:" << endl;
            cout << "Push-ups: " << pushup_time << " sets" << endl;
            cout << "Squats: " << squat_time << " sets" << endl;
            cout << "Planks: " << plank_time << " minutes" << endl;
        }


    } else if (balance < 0) {
        cout << "You need to consume more calories" << endl;
    } else {
        cout << "You are healthy" << endl;
    }
}
int main() {
    Food_Calory food;
    Meal breakfast, lunch, dinner;
    Exercise_name E;
    int option;
    do {
        cout << "Choose an option:" << endl;
        cout << "1.User Information " << endl;
        cout << "2.Calculate Calorie Intake and Exercise advice" << endl;
        cout << "3.Calculate BMI" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your option (1, 2, 3, or 4): ";
        cin >> option;
        cin.ignore(); // To consume the newline character left in the input buffer

        switch (option) {
        case 1: {
            int userOption;
            do {
                cout << "Choose an option:" << endl;
                cout << "1. Add User Information" << endl;
                cout << "2. Update User Information" << endl;
                cout << "3. Delete User Information" << endl;
                cout << "4. Exit" << endl;
                cout << "Enter your option (1, 2, 3, or 4): ";
                cin >> userOption;
                cin.ignore(); // Clear the newline character left in the input buffer
                UserProfileManager person;

                switch (userOption) {
                case 1: {
                    string name;
                    int age;
                    double weight, height;

                    cout << "Enter your name: ";
                    getline(cin, name);

                    cout << "Enter your Age: ";
                    cin >> age;

                    cout << "Enter your weight in kilograms: ";
                    cin >> weight;

                    cout << "Enter your height in meters: ";
                    cin >> height;

                   person= UserProfileManager(name, age, weight, height);

                    break;
                }
                case 2: {
                    string name;
                    int age;
                    double weight, height;

                    cout << "Enter Updated Name: ";

                    getline(cin,name);

                    cout << "Enter Updated Age: ";
                    cin >> age;
                    cin.ignore();

                    cout << "Enter Updated Weight (kg): ";
                    cin >> weight;

                    cout << "Enter Updated Height (meter): ";
                    cin >> height;

                    person.updateUserInfo(name, age, weight, height);

                    break;
                }
                case 3: {
                    person.deleteUserInfo();
                    break;
                }
                case 4: {
                    cout << "Exiting User Information Menu." << endl;
                    break;
                }
                default: {
                    cout << "Invalid option selected." << endl;
                    break;
                }
                }

                if (userOption != 4) {
                    cout << "\nUser Information:" << endl;
                    person.displayUserInfo();
                }
            } while (userOption != 4);
            break;
        }

        case 2: {
            cout << "=== Breakfast ===" << endl;
            breakfast.setMealIntake();

            cout << "=== Lunch ===" << endl;
            lunch.setMealIntake();

            cout << "=== Dinner ===" << endl;
            dinner.setMealIntake();

            long int totalCalories = breakfast.calculateCalorieIntake(food) +
                lunch.calculateCalorieIntake(food) +
                dinner.calculateCalorieIntake(food);

            cout << "Total Calorie Intake for the day: " << totalCalories << " calories" << endl;

            long int balance = balance_calory(totalCalories);
            exercise_choice(E, balance);

            break;
        }
        case 3: {
            string name;
            int age;
            float weight, height;

            //4
            //cin.ignore(); // To consume the newline character left in the input buffer

            cout <<"Enter your name: ";
            getline(cin, name);

            cout << "Enter your Age: ";
            cin >> age;

            cout << "Enter your weight in kilograms: ";
            cin >> weight;

            cout << "Enter your height in meters: ";
            cin >> height;

            UserProfileManager person(name, age, weight, height);
            BMI_Calculator(person);
            break;
        }
        case 4: {
            cout << "Thank you for using our program. Goodbye!" << endl;
            break; // Exit the loop when option 4 is selected
        }
        default: {
            cout << "Invalid option selected." << endl;
            break;
        }
        }

    } while (option != 4);

    return 0;
}
