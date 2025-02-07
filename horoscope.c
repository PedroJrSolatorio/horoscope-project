#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ZODIAC_LENGTH 25
#define NUM_ZODIAC_SIGNS 12
#define NUM_MONTHS 12

// Structure to store zodiac sign data
typedef struct {
    const char* name;
    const char* const* horoscopes;  // Changed to pointer to array of const char*
} ZodiacSign;

// Function prototypes
void toLowerCase(char* str);
int isValidMonth(int month);
int findZodiacIndex(const char* zodiac, const ZodiacSign* signs);
void printHoroscope(const ZodiacSign* signs, const char* zodiac, int month);

// Horoscope messages for each month
static const char* const monthly_horoscopes[NUM_MONTHS] = {
    "Your creative juices are flowing today, and you are raring to take on new challenges. Your workplace may offer some interesting benefits. Remember to relax, your body requires attention every now and then.",
    "You are suggested to not overthink things and work over your life. At some point of the day, you will feel that everything is going better, but some people may try to ruin it. If something like that is going with you, then stay away from them.",
    "You will feel fresh and happy, so remember to start everything again. If you think that nothing was going right for you, then don't give up and try it again. It will help you get better results. The single people may find the love of their life, so don't ignore anyone.",
    "Be patient and work over your life. You should think before you speak as it is important for you today. Even if you will find yourself in a fight with someone, then you are suggested to keep calm and react accordingly.",
    "It is a good day to be brave and you can take your decisions wisely. Think before doing anything. It would be better if you will plan everything and then implement it. Discuss with your family if you want to take any big decision.",
    "Today will not be a too stressful day and you are suggested to stay at home and work over your life. Don't be too stressful over anything as it is a perfect day to chill. Involve yourself with the people who make you happy.",
    "You are suggested to keep calm and be happier. Don't overthink about anything and work harder. Don't be too stiff towards people. You have to keep calm and become a little hotter. If someone is trying spread negativity in your life or demotivate you, simply stay away from them.",
    "Today is a good day to make changes in your life. Some people very close to you may try to ruin your positive attitude, but there is nothing to worry as you are strong. Simply stay away from them and be a judge for yourself. Don't be sad about anything and let it go with the flow.",
    "You can get everything that you were seeking for. There is no need to be affected by someone who is already trying to play pranks on you. It will be a lucky day for women and they can get everything today. Just make sure to maintain a positive and calm attitude.",
    "Maintaining a positive attitude will help you out. Some people may try to hurt you and make your life difficult, so simply stay away from them. Don't involve yourself in the fights. Be happier and calm. You can spend time with your family as they will help you to maintain your positive vibes.",
    "You are suggested to keep calm as this is not the right day for you. You have to prove yourself in many parts of the day. So, maintain a hotter attitude and work over your life. Don't be upset over anything.",
    "You are suggested to not be shy about anything. Speak what feels right to you as it is your point of view. You don't have to get hurt if someone is not listening to you. Express your feelings to your loved ones as it will help you feel better and they will feel lucky."
};

// Initialize zodiac signs data
static const ZodiacSign zodiac_signs[NUM_ZODIAC_SIGNS] = {
    {"aries", monthly_horoscopes},
    {"taurus", monthly_horoscopes},
    {"gemini", monthly_horoscopes},
    {"cancer", monthly_horoscopes},
    {"leo", monthly_horoscopes},
    {"virgo", monthly_horoscopes},
    {"libra", monthly_horoscopes},
    {"scorpio", monthly_horoscopes},
    {"sagittarius", monthly_horoscopes},
    {"capricorn", monthly_horoscopes},
    {"aquarius", monthly_horoscopes},
    {"pisces", monthly_horoscopes}
};

int main() {
    char zodiac[MAX_ZODIAC_LENGTH];
    int month;

    printf("Enter Zodiac: ");
    scanf("%s", zodiac);
    toLowerCase(zodiac);

    printf("Enter Today's Month No. (1-12): ");
    scanf("%d", &month);

    printHoroscope(zodiac_signs, zodiac, month);

    return 0;
}

// Convert string to lowercase for case-insensitive comparison
void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Validate month input
int isValidMonth(int month) {
    return month >= 1 && month <= NUM_MONTHS;
}

// Find index of zodiac sign in array
int findZodiacIndex(const char* zodiac, const ZodiacSign* signs) {
    for (int i = 0; i < NUM_ZODIAC_SIGNS; i++) {
        if (strcmp(zodiac, signs[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

// Print horoscope based on zodiac sign and month
void printHoroscope(const ZodiacSign* signs, const char* zodiac, int month) {
    if (!isValidMonth(month)) {
        printf("Error: Please enter a valid month (1-12).\n");
        return;
    }

    int zodiacIndex = findZodiacIndex(zodiac, signs);
    if (zodiacIndex == -1) {
        printf("Error: Invalid zodiac sign entered.\n");
        return;
    }

    printf("\nHoroscope for %s in month %d:\n", zodiac, month);
    printf("%s\n", signs[zodiacIndex].horoscopes[month - 1]);
}