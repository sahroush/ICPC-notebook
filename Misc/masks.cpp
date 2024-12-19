//all submasks
for (int s=m; ; s=(s-1)&m) {
    ... you can use s ...
    if (s==0)  break;
}
//all masks and their submasks in 3^n
for (int m=0; m<(1<<n); ++m)
    for (int s=m; s; s=(s-1)&m)
        ... s and m ...