import re



with open("input.txt", "r") as f:
    raw_input = f.read()

q =  []
all_lines = raw_input.splitlines()
lines = all_lines[152:]
new_lines = all_lines[:152]
for line in lines:
    bl = line
    line = line.strip()
    m = re.match(r'int (\w+)\[20\] = (\w+)', line)
    if m:
        q.append((m.group(1), m.group(2)))
        continue

    m = re.match(r'move_servo\(.+, (.+)\)', line)
    if m:
        assert len(q) > 0
        qvar, qre_var = q.pop(0)
        var = m.group(1)
        assert var == qvar
        print(var)
        bl = bl.replace(var, qre_var)

    new_lines.append(bl)

out = '\n'.join(new_lines)
with open('final_out.txt', 'w') as f:
    f.write(out)
# print(out)