


def isAnagram(s1, s2):


    if len(s1) != len(s2):
        return False


    count = [0] * 26


    for c in s1:
        count[ord(c) - ord('a')] += 1


    for c in s2:
        count[ord(c) - ord('a')] -= 1


    for cnt in count:
        if cnt != 0:
            return False
    
    return True


s1 = "listen"
s2 = "silent"
print(isAnagram(s1, s2))

s1 = "hello"
s2 = "bello"
print(isAnagram(s1, s2)) 
print(is_anagram("listen", "silent"))
