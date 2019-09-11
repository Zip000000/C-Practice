/*************************************************************************
	> File Name: 04.my_cout.cpp
	> Author: Zip 
	> Mail: 307110017@qq.com 
	> Created Time: 2019年08月05日 星期一 10时59分30秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <string.h>

namespace haizei {
    class ostream {
    public:
        ostream &operator<<(int x) {
            printf("%d", x);
            return *this;
        }
        ostream &operator<<(const std::string &str) {
            printf("%s", str.c_str());
            return *this;
        }
        ostream &operator<<(const double f) {
            char buf[20] = {0};
            sprintf(buf, "%.5e", f);
            int tmp, e_num;
            sscanf(buf, "%d.%de%d", &tmp, &tmp, &e_num);
            
            
            sprintf(buf, "%lf", f);
            //printf("%s\n", buf);
            for (int i = strlen(buf) - 1; i >= 0; i--) {
                if (buf[i] == '0') continue;
                buf[i + 1] = '\0';
                break;
            }
            printf("%s", buf);
            return *this;
        }
    };
    std::string endl = "\n";
    ostream cout;
}
int main() {
    haizei::cout << "haizei world" << haizei::endl;
    haizei::cout << "hahaah" << haizei::endl;
    //std::cout << 123.46 + 123.460000 << std::endl;
    std::cout << 454.1222120000000000000000 << std::endl;
    haizei::cout << 454.122212000000000000 << haizei::endl;
    std::cout << 123.46 << std::endl;
    haizei::cout << 123.46 << haizei::endl;
    
    return 0;
}
