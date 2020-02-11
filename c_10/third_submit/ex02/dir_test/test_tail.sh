tail -c 0 a > d1
./tail -c 0 a > d2
diff d1 d2
./split_case

tail -c 0 f > d1
./tail -c 0 f > d2
diff d1 d2
./split_case

tail -c 0 a b f b c > d1
./tail -c 0 a b f b c > d2 
diff d1 d2
./split_case

tail -c 5 a > d1
./tail -c 5 a > d2
diff d1 d2
./split_case

tail -c 5 a b > d1
./tail -c 5 a b > d2
diff d1 d2
./split_case

tail -c 5 f > d1
./tail -c 5 f > d2
diff d1 d2
./split_case

tail -c 10 a b c d e > d1
./tail -c 10 a b c d e > d2
diff d1 d2
./split_case

tail -c 10000 a b f c d > d1
./tail -c 10000 a b f c d > d2
diff d1 d2
./split_case

tail -c 0 b f c > d1
./tail -c 0 b f c > d2
diff d1 d2
./split_case

tail -c 3 < a b c f d > d1
./tail -c 3 < a b c f d > d2
diff d1 d2
./split_case
