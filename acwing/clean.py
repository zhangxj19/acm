import os
protected = ['in', 'o', 'stdo']
if __name__ == "__main__":
    rootdir = './'
    list = os.listdir(rootdir)  # 列出文件夹下所有的目录与文件
    for i in range(0, len(list)):
        filename = list[i]
        path = os.path.join(rootdir, list[i])
        # if os.path.isfile(path):
        # # 你想对文件的操作
        if '.cpp' in filename or '.py' in filename or '.sh' in filename:
            continue
        
        if filename in protected:
            continue
            
        if os.path.isdir(filename):
            continue
            
        print(filename)
        os.remove(filename)
        
