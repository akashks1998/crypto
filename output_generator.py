import pyautogui as auto
import time
file_object=open("input_in_string.txt","r+")
time.sleep(15)
arr = file_object.readlines()
for inp in arr:
    auto.click(1209,920, button='left')
    to_input=list(inp)
    auto.typewrite(to_input)
    time.sleep(0.01)
    auto.press('enter')
    time.sleep(0.02)
    auto.doubleClick(536,837, button='left')
    auto.keyDown('ctrlleft');auto.press('c');auto.keyUp('ctrlleft')
    auto.click(1475,1043,button='left')
    auto.keyDown('ctrlleft');auto.press('v');auto.keyUp('ctrlleft')
    auto.press('enter')

auto.moveTo(1475,1043)
auto.keyDown("ctrlleft");auto.press('s');auto.keyUp("ctrlleft")
