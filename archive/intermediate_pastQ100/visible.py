import os

# ディレクトリを指定
directory = "C:/programming/atcoder/archive/intermediate_pastQ100"

# 1から100までのフラグを初期化
flags = [False] * 100

# ディレクトリ内のファイル名を取得
for filename in os.listdir(directory):
    try:
        number, ext = os.path.splitext(filename)
        number = int(number)
        if 1 <= number <= 100 and ext == '.cpp':
            flags[number - 1] = True
    except ValueError:
        continue

# フラグを10x10配列でMarkdownファイルに保存
with open("README.md", "w", encoding='utf-8') as f:
    f.write("競技プログラミングのアーカイブ\n\n")
    f.write("## 過去問精選100問 進行状況\n\n")
    f.write("|   #   | Status |   #   | Status |   #   | Status |   #   | Status |   #   | Status |\n")
    f.write("|:-----:|:------:|:-----:|:------:|:-----:|:------:|:-----:|:------:|:-----:|:------:|\n")
    
    for i, flag in enumerate(flags, 1):
        if i % 10 == 1:
            f.write("|")
        f.write(f" {i:3} | {'✓' if flag else ' '} |")
        if i % 10 == 0:
            f.write("\n")
