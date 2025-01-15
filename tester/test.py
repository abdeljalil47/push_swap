import random
import subprocess

RED = '\033[31m'      # Red
GREEN = '\033[32m'    # Green
BLUE = '\033[34m'     # Blue
RESET = '\033[0m'     # Reset color

print(f"""{BLUE}
$$$$$$$$\ $$$$$$$$\  $$$$$$\ $$$$$$$$\ $$$$$$$$\ $$$$$$$\  
\__$$  __|$$  _____|$$  __$$\\__ $$  __|$$  _____|$$  __$$\ 
   $$ |   $$ |      $$ /  \__|  $$ |   $$ |      $$ |  $$ |
   $$ |   $$$$$\    \$$$$$$\    $$ |   $$$$$\    $$$$$$$  |
   $$ |   $$  __|    \____$$\   $$ |   $$  __|   $$  __$$< 
   $$ |   $$ |      $$\   $$ |  $$ |   $$ |      $$ |  $$ |
   $$ |   $$$$$$$$\ \$$$$$$  |  $$ |   $$$$$$$$\ $$ |  $$ |
   \__|   \________| \______/   \__|   \________|\__|  \__|
                                                           
                                                           
                                                           
""")

n = int(input("number of numbers -> "))
nn = int(input("max of instructions -> "))

for j in range(10**5):
    print(f"{BLUE}Test {j}{RESET}")
    lst = set()
    while len(lst) < n:
        aid = random.randint(-1000, 9000000)
        lst.add(aid)
    text = "./push_swap " + " ".join(map(str, lst)) + " | wc -l"
    result = subprocess.run(text, shell=True, capture_output=True, text=True)
    try:
        output = int(result.stdout.strip())
        print(f"Numbers: {lst}")
        if output < nn:
            print(f"{GREEN}Instructions: {output}")
        if output >= nn:
            print(f"{RED}-> Found a set with >= {nn} instructions!{RESET}")
            print(f"{RED}Command: {text}{RESET}")
            break
        else:
            print(f"{RED}Instructions are below {nn}, continuing...{RESET}")
    except ValueError:
        print(f"{RED}Error in command output: {result.stdout}{RESET}")
