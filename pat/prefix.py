import os

if __name__ == "__main__":
    # 列出当前目录下所有的文件
    files = os.listdir('.')  # 如果path为None，则使用path = '.' 

    for filename in files:
        portion = os.path.splitext(filename)  # 分离文件名与扩展名
        # 如果后缀是jpg
        if portion[0][0] != 'a' and portion[0][0] in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']:
            # 重新组合文件名和后缀名
            newname = 'a' + portion[0] + portion[1]
            print(f'{filename} -> {newname}')
            # if os.path.exists(filename) and os.path.isfile(filename):
            #     os.rename(filename, newname)
    