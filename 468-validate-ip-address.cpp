class Solution {
public:
const string IPV4 = "IPv4";
const string IPV6 = "IPv6";
const string ERROR = "Neither";

std::vector<std::string> customSplit (const string& ip, char del) {
    std::vector<std::string>ans;
    std::string str = "";
    for (auto s : ip) {
        if (s == del && str != "") {
            ans.push_back(str);
            str = "";
            continue;
        }
        str+=s;
    }
    ans.push_back(str);
    return ans;
}

bool checkIPv4(const string& point) {
    if (point == "" || point.size()>3) return false;
    int i = 0;
    for (auto p : point) {
        if (p<'0' || p>'9') return false;
        i=i*10+(int)p - '0';
    }
    if (point.size()>1 && point[0] == '0') return false;
    return (i>=0 && i <=255);
}

bool checkIPv6(const string& point) {
    if (point == "" || point.size() > 4) return false;
    for (auto p : point) {
        if ((p>='0'&&p<='9')||(p>='a' && p<='f')||(p>='A'&&p<='F')) {
            continue;
        }
        return false;
    }
    return true;
}

    string validIPAddress(string queryIP) {
        //checker IPv4
    auto a = customSplit(queryIP, '.');
    if (a.size() == 4) {
        for (auto point : a) {
            if (!checkIPv4(point)) {
                return ERROR;
            }
        }
        return IPV4;
    }
    //checker IPv6
    a = customSplit(queryIP, ':');
    if (a.size() == 8) {
        for (auto point : a) {
            if (!checkIPv6(point)) {
                return ERROR;
            }
        }
        return IPV6;
    }
    return ERROR;
    }
};