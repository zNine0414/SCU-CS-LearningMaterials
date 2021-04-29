
def encrypt():
    text = input("请输入需要加密的文本（任意大小写字母组合）：")
    cipher_text = ' '
    for i in text:
        if 'a' <= i <= 'z':
            cipher_text += chr(ord('a') + ((ord(i) - ord('a')) + 4) % 26)
        if 'A' <= i <= 'Z':
            cipher_text += chr(ord('A') + ((ord(i) - ord('A')) + 4) % 26)
    print("加密文本：",cipher_text)
def decrypt():
    cipher_text = input("请输入需要解密的文本（任意大小写字母组合）：")
    text = ' '
    for i in cipher_text:
        if 'a' <= i <= 'z':
            text += chr(ord('a') + ((ord(i) - ord('a')) - 4) % 26)
        if 'A' <= i <= 'Z':
            text += chr(ord('A') + ((ord(i) - ord('A')) - 4) % 26)
    print("原始文本：", text)


encrypt()
decrypt()