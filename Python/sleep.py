import time

import pyautogui

# 设定计时的总时长（37分钟）
total_time = 37 * 60
# 循环等待
for seconds in range(total_time, 0, -1):
    # 打印剩余时间

    print("剩余时间: {} 分 {} 秒".format(seconds // 60, seconds % 60))

    time.sleep(1)  # 等待1秒


# 使用 pyautogui 来执行显示桌面的操作
pyautogui.hotkey("win", "d")  # 按下 Windows+D 组合键显示桌面
