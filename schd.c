//This program is created by Shad Ahammed to create an agenda for a grandma
//Program will be active when a schedule task begins, 10 minutes before its finishing time, when a time is inserted to check
//The program has 2 modes
//In silent mode program will automatically give output when a scheduled task start
//In check mode, user has to give time and minute to check the activity this schedule belong

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
//#include <conio.h>

time_t now;
struct tm *rightnow;

//Declaring the variables
int hour, min, sec;
int remainTime;
int i;
char answer;
char exitkey;
char CheckKey;
char ScheduleKey;

//Creating a schedule for task start and end
int HourStartSchedule[] =        {8,9,10,12,16,18,19,20,21,7};
int MinuteStartSchedule[]=       {00,00,00,00,00,00,00,00,00,00};
int HourEndSchedule[]=      {8,9,10,12,16,18,19,20};
int MinuteEndSchedule[]=    {30,30,30,30,30,30,30,30};

//Declaring the task ids
int activity1ID, activity2ID, activity3ID,activity4ID,activity5ID,activity6ID,activity7ID,activity8ID,activity9ID,activity10ID;
int CheckDone1ID, CheckDone2ID, CheckDone3ID,CheckDone4ID,CheckDone5ID,CheckDone6ID,CheckDone7ID,CheckDone8ID,CheckDone9ID;

//Prototype functions
int BreakfastCheck();
int DaySugarTestCheck();
int ShoppingCheck();
int LunchCheck();
int ExerciseTimeCheck();
int TvshowCheck();
int DinnerCheck();
int MedicineCheck();
int DayEnd();
void activityDone();
void DayFinish();
void DayStart();
void CheckSchedule();
void delay(int number_of_seconds);
int remainTimeCalc();


int main()
{
    //Storing the current time inside 'rightnow' variable

    now = time(NULL);
    rightnow = localtime(&now);

    printf("Current Day and Time now: %s\n",ctime(&now));
    printf("Please press any key whenever you want to shift from silent to check mode\n\n\n");

    //The infinite loop of schedule checking

    while(1)
    {
        now = time(NULL);
        rightnow = localtime(&now);
        hour = rightnow->tm_hour;
        min = rightnow->tm_min;
        sec = rightnow->tm_sec;

        //Start checking the schedule

        //Checking Breakfast schedule

        if(hour == HourStartSchedule[0] && min == MinuteStartSchedule[0] && activity1ID != 1 && CheckDone1ID !=1)
        {
            BreakfastCheck();

            if (activity1ID == 1)
            {
                activityDone();
            }
            else
            {
                printf("Your breakfast is pending\n");
            }
            CheckDone1ID =1;
        }

        else if( ((HourEndSchedule[0]-hour)*3600 + (MinuteEndSchedule[0] - min)*60) == 600 && activity1ID != 1 && CheckDone1ID !=2)
        {
            printf("Only 10 minutes remaining for breakfast\n");
            CheckDone1ID = 2;
        }

        //Checking Morning time sugar test schedule

        if(hour == HourStartSchedule[1] && min == MinuteStartSchedule[1] && activity2ID != 1 && CheckDone2ID != 1)
        {
            DaySugarTestCheck();

            if (activity2ID == 1)
            {
                activityDone();
            }
            else
            {
                printf("You did not check your sugar yet\n");
            }
             CheckDone2ID = 1;
        }

        else if( ((HourEndSchedule[1]-hour)*3600 + (MinuteEndSchedule[1] - min)*60) == 600 && activity2ID != 1 && CheckDone2ID !=2)
        {
            printf("Only 10 minutes remaining for sugar test\n");
            CheckDone2ID = 2;
        }

        //Checking shopping schedule

        if(hour == HourStartSchedule[2] && min == MinuteStartSchedule[2] && activity3ID != 1 && CheckDone3ID != 1)
        {
            ShoppingCheck();

            if (activity3ID == 1)
            {
                activityDone();
            }
            else
            {
                printf("Your shopping is pending\n");
            }
            CheckDone3ID = 1;
        }

        else if( ((HourEndSchedule[2]-hour)*3600 + (MinuteEndSchedule[2] - min)*60) == 600 && activity3ID != 1 && CheckDone3ID !=2)
        {
            printf("Only 10 minutes remaining for shopping\n");
            CheckDone3ID = 2;
        }

        //Checking Lunch schedule
        if(hour == HourStartSchedule[3] && min == MinuteStartSchedule[3] && activity4ID != 1 && CheckDone4ID != 1)
        {
            LunchCheck();

            if (activity4ID == 1)
            {
                activityDone();
            }
            else
            {
                printf("Your lunch is pending\n");
            }
            CheckDone4ID = 1;
        }

        else if( (HourEndSchedule[3]-hour)*3600 + (MinuteEndSchedule[3] - min)*60 == 600 && activity4ID != 1 && CheckDone4ID !=2)
        {
            printf("Only 10 minutes remaining for lunch\n");
            CheckDone4ID = 2;
        }

        //Checking Exercise schedule
        if(hour == HourStartSchedule[4] && min == MinuteStartSchedule[4] && activity5ID != 1 && CheckDone5ID != 1)
        {
            ExerciseTimeCheck();

            if (activity5ID == 1)
            {
                activityDone();
            }
            else
            {
                printf("Your exercise for today is pending\n");
            }
            CheckDone5ID = 1;

        }

        else if( ((HourEndSchedule[4]-hour)*3600 + (MinuteEndSchedule[4] - min)*60) == 600 && activity5ID != 1 && CheckDone5ID !=2)
        {
            printf("Only 10 minutes remaining for exercise\n");
            CheckDone5ID = 2;
        }

        //Checking Tvshow schedule

        if(hour == HourStartSchedule[5] && min == MinuteStartSchedule[5] && activity6ID != 1 && CheckDone6ID != 1)
        {
            TvshowCheck();

            if (activity6ID == 1)
            {
                activityDone();
            }
            else
            {
                printf("Your Tv show time is pending\n");
            }
            CheckDone6ID = 1;
        }

        else if( ((HourEndSchedule[5]-hour)*3600 + (MinuteEndSchedule[5] - min)*60) == 600 && activity6ID != 1 && CheckDone6ID !=2)
        {
            printf("Only 10 minutes remaining for TV show\n");
            CheckDone6ID = 2;
        }

        //Checking Dinner schedule

        if(hour == HourStartSchedule[6] && min == MinuteStartSchedule[6] && activity7ID != 1 && CheckDone7ID != 1)
        {
            DinnerCheck();

            if (activity7ID == 1)
            {
                activityDone();
            }
            else
            {
                printf("Your dinner is pending\n");
            }
            CheckDone7ID = 1;
        }

        else if( ((HourEndSchedule[6]-hour)*3600 + (MinuteEndSchedule[6] - min)*60) == 600 && activity7ID != 1 && CheckDone7ID !=2)
        {
            printf("Only 10 minutes remaining for dinner\n");
            CheckDone7ID = 2;
        }

        //Checking Medicine schedule

        if(hour == HourStartSchedule[7] && min == MinuteStartSchedule[7] && activity8ID != 1 && CheckDone8ID != 1)
        {
            MedicineCheck();

            if (activity8ID == 1)
            {
                activityDone();
            }
            else
            {
                printf("You did not take your medicine\n");
            }
            CheckDone8ID = 1;
        }

        else if( (HourEndSchedule[7]-hour)*3600 + (MinuteEndSchedule[7] - min)*60 == 600 && activity8ID != 1 && CheckDone8ID !=2)
        {
            printf("Only 10 minutes remaining for taking medicine\n");
            CheckDone8ID = 2;
        }
        else if(hour == HourStartSchedule[8] && min == MinuteStartSchedule[8] && activity9ID != 1)
        {
            DayFinish();
            printf("See you tomorrow morning\n");
        }
        else if(hour == HourStartSchedule[9] && min == MinuteStartSchedule[9] && activity10ID != 1)
        {
            printf("Good morning\n");
            DayStart();
        }
        if (activity9ID == 1 && CheckDone9ID != 1)
        {
            delay(3);
            printf("Good Night!\n");
            CheckDone9ID = 1;
        }

        while(kbhit())
        {
            CheckSchedule();
            if (exitkey == 'y')
            {
                break;
            }
        }
    }
}
void activityDone()
{
    printf("Great, Job is done. Waiting for next Job\n");
    remainTimeCalc();
    printf("Your next schedule will start after %d minutes\n\n\n", remainTime);
    printf("Please press any key+ ENTER to go to schedule checker\n");
}
int BreakfastCheck()
{
    printf("Breakfast Time! Please press y if you want have it now : ");
    scanf("%s",&answer);

    if (answer == 'y')
    {
        printf("Status of this Breakfast activity is DONE\n");
        goto done;
    }

    else
    {
        printf("Status of this Breakfast activity is UNDONE\n");
        goto undone;
    }

    done:
        activity1ID = 1;
        return activity1ID;
    undone:
        activity1ID = 0;
        return activity1ID;
}
int DaySugarTestCheck()
{
    printf("Sugar checking Time! Please press y if you want have it now : ");
    scanf("%s",&answer);

    if (answer == 'y')
    {
        printf("Status of this sugar test activity is DONE\n");
        goto done;
    }

    else
    {
        printf("Status of this sugar test activity is UNDONE\n");
        goto undone;
    }

    done:
        activity2ID = 1;
        return activity2ID;
    undone:
        activity2ID = 0;
        return activity2ID;
}

int ShoppingCheck()
{
    printf("Shopping Time! Please press y if you want have it now : ");
    scanf("%s",&answer);

    if (answer == 'y')
    {
        printf("Status of this shop time activity is DONE\n");
        goto done;
    }

    else
    {
        printf("Status of this shop time activity is UNDONE\n");
        goto undone;
    }

    done:
        activity3ID = 1;
        return activity3ID;
    undone:
        activity3ID = 0;
        return activity3ID;
}
int LunchCheck()
{
    printf("Lunch Time! Please press y if you want have it now : ");
    scanf("%s",&answer);
    if (answer == 'y')
    {
        printf("Status of this lunch activity is DONE\n");
        goto done;
    }
    else
    {
        printf("Status of this lunch activity is UNDONE\n");
        goto undone;
    }
    done:
        activity4ID = 1;
        return activity4ID;
    undone:
        activity4ID = 0;
        return activity4ID;
}

int ExerciseTimeCheck()
{
    printf("Exercise Time! Please press y if you want have it now : ");
    scanf("%s",&answer);

    if (answer == 'y')
    {
        printf("Status of this exercise activity is DONE\n");
        goto done;
    }

    else
    {
        printf("Status of this exercise activity is UNDONE\n");
        goto undone;
    }

    done:
        activity5ID = 1;
        return activity5ID;
    undone:
        activity5ID = 0;
        return activity5ID;
}

int TvshowCheck()
{
    printf("Tvshow Time! Please press y if you want have it now : ");
    scanf("%s",&answer);

    if (answer == 'y')
    {
        printf("Status of this tv show activity is DONE\n");
        goto done;
    }

    else
    {
        printf("Status of this tv show activity is UNDONE\n");
        goto undone;
    }

    done:
        activity6ID = 1;
        return activity6ID;
    undone:
        activity6ID = 0;
        return activity6ID;
}

int DinnerCheck()
{
    printf("Dinner Time! Please press y if you want have it now : ");
    scanf("%s",&answer);

    if (answer == 'y')
    {
        printf("Status of this dinner activity is DONE\n");
        goto done;
    }

    else
    {
        printf("Status of this dinner activity is UNDONE\n");
        goto undone;
    }

    done:
        activity7ID = 1;
        return activity7ID;
    undone:
        activity7ID = 0;
        return activity7ID;
}

int MedicineCheck()
{
    printf("Medicine Time! Please press y if you want have it now : ");
    scanf("%s",&answer);

    if (answer == 'y')
    {
        printf("Status of this medicine check activity is DONE\n");
        goto done;
    }

    else
    {
        printf("Status of this medicine check activity is UNDONE\n");
        goto undone;
    }

    done:
        activity8ID = 1;
        return activity8ID;
    undone:
        activity8ID = 0;
        return activity8ID;
}

//This function will declare a day is finished

void DayFinish()
{
    printf("Day is Finished\n");

    activity9ID = 1;
    activity10ID = 0;
}
//This function will declare a day is finished

void DayStart()
{
    delay(3);
    printf("I wish you a nice day today\n");

    activity10ID = 1;
    activity1ID, activity2ID, activity3ID,activity4ID,activity5ID,activity6ID,activity7ID,activity8ID,activity9ID = 0;
    CheckDone1ID, CheckDone2ID, CheckDone3ID,CheckDone4ID,CheckDone5ID,CheckDone6ID,CheckDone7ID,CheckDone8ID,CheckDone9ID = 0;
}


//This function will create a delay in seconds based on the input given

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

//This function will return the name of schedule for a specific time

void CheckSchedule()
{
    int h,m;
    now = time(NULL);
    rightnow = localtime(&now);
    int TimeThreshold = 30; //It indicates minutes threshold of a task to be recognized before or after its scheduled start time
    while(1)
    {
        printf("To check schedule, please enter the hour: ");
        scanf("%d",&h);
        printf("Now enter the minute: ");
        scanf("%d",&m);
        if (abs( (h - HourStartSchedule[0])*60 + (m - MinuteStartSchedule[0]) ) <= TimeThreshold)
        {
            printf("This schedule belongs to your breakfast task\n");
            if (activity1ID == 0)
            {
                delay(3);
                BreakfastCheck();
            }
            else
            {
                printf("You did your breakfast already\n");
            }
        }
        else if (abs( (h - HourStartSchedule[1])*60 + (m - MinuteStartSchedule[1]) ) <= TimeThreshold)
        {
            printf("This schedule belongs to your sugar test task\n");
            if (activity2ID == 0)
            {
                delay(3);
                DaySugarTestCheck();
            }
            else
            {
                printf("You did your sugar test already\n");
            }
        }

        else if (abs( (h - HourStartSchedule[2])*60 + (m - MinuteStartSchedule[2]) ) <= TimeThreshold)
        {
            printf("This schedule belongs to your shopping task\n");
            if (activity3ID == 0)
            {
                delay(3);
                ShoppingCheck();
            }
            else
            {
                printf("You did your shopping already\n");
            }
        }

        else if (abs((h - HourStartSchedule[3])*60 + (m - MinuteStartSchedule[3])) <= TimeThreshold)
        {
            printf("This schedule belongs to your lunch task\n");
            if (activity4ID == 0)
            {
                delay(3);
                LunchCheck();
            }
            else
            {
                printf("You did your lunch already\n");
            }
        }

        else if ( abs((h - HourStartSchedule[4])*60 + (m - MinuteStartSchedule[4] )) <= TimeThreshold)
        {
            printf("This schedule belongs to your exercise task\n");
            if (activity5ID == 0)
            {
                delay(3);
                ExerciseTimeCheck();
            }
            else
            {
                printf("You did your exercise already\n");
            }
        }

        else if (abs((h - HourStartSchedule[5])*60 + (m - MinuteStartSchedule[5])) <= TimeThreshold)
        {
            printf("This schedule belongs to your tv show task\n");
            if (activity6ID == 0)
            {
                delay(3);
                TvshowCheck();
            }
            else
            {
                printf("You are watching your tv show already\n");
            }
        }

        else if (abs((h - HourStartSchedule[6])*60 + (m - MinuteStartSchedule[6])) <= TimeThreshold)
        {
            printf("This schedule belongs to your dinner task\n");
            if (activity7ID == 0)
            {
                delay(3);
                DinnerCheck();
            }
            else
            {
                printf("You did your dinner already\n");
            }
        }

        else if (abs((h - HourStartSchedule[7])*60 + (m - MinuteStartSchedule[7])) <= TimeThreshold)
        {
            printf("This schedule belongs to your medicine taking task\n");
            if (activity8ID == 0)
            {
                delay(3);
                MedicineCheck();
            }
            else
            {
                printf("You took your medicine already\n");
            }
        }
        else
        {
            printf("Nothing is scheduled this time particularly\n");
        }

        printf("Please press y to go back to silent mode or any key to check again : ");
        scanf("%s",&exitkey);
        if(exitkey == 'y')
        {
            printf("The program is in silent mode now\n");
            remainTimeCalc();
            printf("Your next schedule will start after %d minutes\n\n\n", remainTime);
            printf("Please press any key whenever you want to shift from silent to check mode\n\n\n");
            break;
        }
        else
        {
            continue;
        }
}
}

//This function will check the time remaining for next schedule in minutes

int remainTimeCalc()
{
    if (hour < HourStartSchedule[0])
    {
        i= 0;
    }
    if ( hour >= HourStartSchedule[0] && hour < HourStartSchedule[1] )
    {
        i= 1;
    }
    if ( hour >= HourStartSchedule[1] && hour < HourStartSchedule[2] )
    {
        i= 2;
    }
    if ( hour >= HourStartSchedule[2] && hour < HourStartSchedule[3] )
    {
        i= 3;
    }
    if ( hour >= HourStartSchedule[3] && hour < HourStartSchedule[4] )
    {
        i= 4;
    }
    if ( hour >= HourStartSchedule[4] && hour < HourStartSchedule[5] )
    {
        i= 5;
    }
    if ( hour >= HourStartSchedule[5] && hour < HourStartSchedule[6] )
    {
        i= 6;
    }
    if ( hour >= HourStartSchedule[6] && hour < HourStartSchedule[7] )
    {
        i= 7;
    }
    remainTime = (HourStartSchedule[i]- hour)*60 + (MinuteStartSchedule[i]- min);
    return remainTime;
}
