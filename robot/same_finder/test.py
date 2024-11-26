import re

with open("input.txt", "r") as f:
    raw_input = f.read()

# print(raw_input)
res = [m[0] for m in re.findall(r"(\{(\d{1,3},?\s?)+\})", raw_input)]
print(res)
print(len(res))

up = set(res)
print(len(set(res)))

poses = {}

for i, pose in enumerate(up):
    pose_name = f'pose_{i:03d}'
    pose_val = pose
    # print(f'const int {pose_name}[] = {pose};')
    raw_input = raw_input.replace(pose, pose_name)

    poses[pose_name] = pose


for pose_name, pose in poses.items():
    raw_input = f'const int {pose_name}[] = {pose};\n' + raw_input


with open("output.txt", "w") as f:
    f.write(raw_input)

