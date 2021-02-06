import os

cntCPP = 0

# 遍历文件夹

def walkFile(file):
    global cntCPP
    for root, dirs, files in os.walk(file):

        # root 表示当前正在访问的文件夹路径
        # dirs 表示该文件夹下的子目录名list
        # files 表示该文件夹下的文件list

        # 遍历文件
        for f in files:
            if '.cpp' in f:
                cntCPP += 1
                # print(os.path.join(root, f))

        # 遍历所有的文件夹
        # for d in dirs:
            # if(d == '')
            # walkFile(os.path.join(root, d))
            # print(os.path.join(root, d))


if __name__ == "__main__":
    walkFile('./')
    print(f"{cntCPP} cpp files")
    pass