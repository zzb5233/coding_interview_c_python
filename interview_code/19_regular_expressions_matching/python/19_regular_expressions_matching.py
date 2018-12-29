# -*- coding: utf-8 -*=



def match_core(s_str, pattern):
    if 0 == len(s_str) and 0 == len(pattern):
        return True
    if 0 != len(s_str) and 0 == len(pattern):
        return False
    
    if len(pattern) > 1 and pattern[1] == '*':
        if 0 != len(s_str) and (pattern[0] == s_str[0] or pattern[0] == '.'):
            return match_core(s_str[1:], pattern[2:]) or match_core(s_str[1:], pattern) or match_core(s_str, pattern[2:])
        else:
            return match_core(s_str, pattern[2:])
    
    if (0 != len(s_str) and s_str[0] == pattern[0]) or (pattern[0] == '.' and len(s_str) != 0):
        return match_core(s_str[1:], pattern[1:])
    
    if pattern[0] == '.' and len(s_str) == 1:
        return True
    return False
    
def match(s_str, pattern):
    if None == s_str or None == pattern:
        return False
    return match_core(s_str, pattern)

def test(test_name, s_str, pattern, expected):
    if match(s_str, pattern) == expected:
        print('%s: pass' % test_name)
    else:
        print('%s: failed' % test_name)
if __name__ == '__main__':
    
    test("test01", "", "", True)
    test("test02", "", ".*", True)
    test("test03", "", ".", False)
    test("test04", "", "c*", True)
    test("test05", "a", ".*", True)
    test("test06", "a", "a.", False)
    test("test07", "a", "", False)
    test("test08", "a", ".", True)
    test("test09", "a", "ab*", True)
    test("test10", "a", "ab*a", False)
    test("test11", "aa", "aa", True)
    test("test12", "aa", "a*", True)
    test("test13", "aa", ".*", True)
    test("test14", "aa", ".", False)
    test("test15", "ab", ".*", True)
    test("test16", "ab", ".*", True)
    test("test17", "aaa", "aa*", True)
    test("test18", "aaa", "aa.a", False)
    test("test19", "aaa", "a.a", True)
    test("test20", "aaa", ".a", False)
    test("test21", "aaa", "a*a", True)
    test("test22", "aaa", "ab*a", False)
    test("test23", "aaa", "ab*ac*a", True)
    test("test24", "aaa", "ab*a*c*a", True)
    test("test25", "aaa", ".*", True)
    test("test26", "aab", "c*a*b", True)
    test("test27", "aaca", "ab*a*c*a", True)
    test("test28", "aaba", "ab*a*c*a", False)
    test("test29", "bbbba", ".*a*a", True)
    test("test30", "bcbbabab", ".*a*a", False)