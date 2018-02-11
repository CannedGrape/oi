program match;
var n,s,j,i,m,h,g,t:longint;
    a,b,c:array[1..100000]of int64;
  begin
    assign(input,'match.in');
    reset(input);
    assing(output,'match.out');
    rewrite(output);
    s:=0;
    readln(n);
    for i:=1 to n do
     read(a[i]);
    readln;
    for i:=1 to n do
     read(b[i]);
    for i:=1 to n do
     begin
      c[i]:=a[i]-b[i];
      if c[i]<0 then c[i]:=b[i]-a[i];
     end;
    for i:=1 to n do
      for j:=1 to n do
       begin
         m:=a[i]-b[j];
         g:=a[j]-b[i];
         if m<0 then m:=b[j]-a[i];
         if g<0 then g:=b[i]-a[j];
         if (c[i]+c[j]>m+g) then
          begin
            c[i]:=m;
            c[j]:=g;
            t:=b[i];
            b[i]:=b[j];
            b[j]:=t;
            s:=s+1;
          end;
       end;
    if s>99999997 then s:=s mod 99999997;
    writeln(s);
    readln;
    close(input);
    close(output);
  end.

