 (left >= 1) {  
        if (left < k) { //剩余字符全部反转。
            reverse (s, upbd - left + 1,upbd); // 区间[]
            break;
        } else {
            reverse (s, upbd - left + 1,upbd - left + k); // 区间[]
            left -= 2 * k;
        } // if ((length - j) < k)
    }
        
    cout 