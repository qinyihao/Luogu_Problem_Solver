global Time
Time = 0
global Day
Day = 0
global Flag
Flag = False
def JudgeUnHappy(School, Plan, JudgeDay):
    global Time
    global Day
    global Flag
    Totaltime = School + Plan
    if (Totaltime > 8):
        Flag = True
        if (Totaltime > Time):
            Time = Totaltime
            Day = JudgeDay

def main():
    n = 1
    while (n <= 7):
        School, Plan = map(int,input().split())
        JudgeUnHappy(School, Plan, n)
        n += 1

    if Flag:
        print(Day)
    else:
        print("0")

main()
