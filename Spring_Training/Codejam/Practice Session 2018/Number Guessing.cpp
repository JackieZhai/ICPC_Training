 #include <bits/stdc++.h>

//
// int T;
// int A, B;
// int N;
//
//
// int main()
// {
//     cin>>T;
//     while(T--)
//     {
//        cin>>A>>B>>N;
//        int l=A, r=B;
//        string s;
//
//        while(N--)
//        {
//            int mid=(l+r)/2+1;
//            cout<<mid<<endl;
//            cin>>s;
//            if(s[0]=='T')
//            {
//                if(s[4]=='B')
//                {
//                    r=mid;
//                }
//                else
//                {
//                    l=mid;
//                }
//            }
//            else if(s[0]=='W')
//            {
//                return -1;
//            }
//            else if(s[0]=='C')
//            {
//                l=A, r=B;
//                continue;
//            }
//        }
//
//
//
//     }
//
//
//
//     return 0;
// }



int main() {
  int num_test_cases;
  std::cin >> num_test_cases;
  for (int i = 0; i < num_test_cases; ++i) {
    int lo, hi;
    std::cin >> lo >> hi;
    int num_tries;
    std::cin >> num_tries;
    int head = lo + 1, tail = hi;
    while (true) {
      int m = (head + tail) / 2;
      std::cout << m << std::endl;
      std::string s;
      std::cin >> s;
      if (s == "CORRECT") break;
      if (s == "TOO_SMALL")
        head = m + 1;
      else
        tail = m - 1;
    }
  }
  return 0;
}
