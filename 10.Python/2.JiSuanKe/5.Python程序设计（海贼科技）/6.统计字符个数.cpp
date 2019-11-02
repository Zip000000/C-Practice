string=raw_input()
alph_cnt = dig_cnt = spa_cnt = oth_cnt = 0
for ch in string:
    if ch.isalpha():
        alph_cnt+=1
    elif ch.isdigit():
        dig_cnt+=1
    elif ch == ' ':
        spa_cnt+=1
    else:
        oth_cnt+=1

print alph_cnt, dig_cnt, spa_cnt, oth_cnt