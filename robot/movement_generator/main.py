with open("input.txt", "r") as f:
    raw_input = f.read()

all_lines = raw_input.splitlines()
with open('output.txt', 'a') as f:
    for m in all_lines:
        text = '\nelse if(movement == "' + m + '"){\n\thashv3.' + m + '(repeats, speed);\n}'
        f.write(text)
