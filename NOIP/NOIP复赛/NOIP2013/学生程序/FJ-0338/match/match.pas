var c,f:array[0..100000,0..4]of longint;
    a,b:array[0..100000]of longint;
    i,n,x0,x1,x2,x3,x4,y1,y2,z1,z2,min,min1:longint;
begin
  assign(input,'match.in');reset(input);
  assign(output,'match.out');rewrite(output);
    readln(n);
    for i:=1 to n do read(a[i]);readln;
    for i:=1 to n do read(b[i]);readln;
    f[1,0]:=(a[1]-b[1])*(a[1]-b[1]);c[1,0]:=0;
    f[1,3]:=sqr(a[1]-b[2]);c[1,3]:=1;
    f[1,4]:=sqr(a[2]-b[1]);c[1,4]:=1;
    f[2,0]:=f[1,0]+sqr(a[1]-b[2]);c[2,0]:=0;
    f[2,1]:=f[1,3]+sqr(a[2]-b[1]);c[2,1]:=1;
    f[2,2]:=f[1,4]+sqr(a[1]-b[2]);c[2,2]:=1;
    f[2,3]:=f[1,0]+sqr(a[2]-b[3]);c[2,3]:=1;
    f[2,4]:=f[1,0]+sqr(a[3]-b[2]);c[2,4]:=1;
    for i:=1 to n do
    begin
      y1:=f[i-1,1];z1:=c[i-1,1];
      y2:=f[i-1,2];z2:=c[i-1,2];
      x0:=sqr(a[i]-b[i]);x1:=sqr(a[i]-b[i-1]);x2:=sqr(a[i-1]-b[i]);
      f[i,0]:=f[i-1,0];c[i,0]:=c[i-1,0];
      if (y1<f[i,0])or(y1=f[i,0])and(z1<c[i,0]) then
      begin
        f[i,0]:=y1;c[i,0]:=z1;
      end;
      if (y2<f[i,0])or(y2=f[i,0])and(z2<c[i,0]) then
      begin
        f[i,0]:=y2;c[i,0]:=z2;
      end;f[i,0]:=f[i,0]+x0;
      f[i,1]:=c[i-1,3]+x1;c[i,1]:=c[i-1,3];
      f[i,2]:=c[i-1,4]+x2;c[i,2]:=c[i-1,4];
      if i<n then
      begin
        x3:=sqr(a[i]-b[i+1]);x4:=sqr(a[i+1]-b[i]);
        f[i,3]:=f[i-1,0];c[i,3]:=c[i-1,0];
        if (y1<f[i,3])or(y1=f[i,3])and(z1<c[i,3]) then
        begin
          f[i,3]:=y1;c[i,3]:=z1;
        end;
        if (y2<f[i,3])or(y2=f[i,3])and(z2<c[i,3]) then
        begin
          f[i,3]:=y2;c[i,3]:=z1;
        end;f[i,3]:=f[i,3]+x3;inc(c[i,3]);
        f[i,4]:=f[i-1,0];c[i,4]:=c[i-1,0];
        if (y1<f[i,4])or(y1=f[i,4])and(z1<c[i,4]) then
        begin
          f[i,4]:=y1;c[i,4]:=z1;
        end;
        if (y2<f[i,4])or(y2=f[i,4])and(z2<c[i,4]) then
        begin
          f[i,4]:=y2;c[i,4]:=z1;
        end;f[i,4]:=f[i,4]+x3;inc(c[i,4]);
      end;
    end;
    min:=f[n,0];min1:=c[n,0];
    if (f[n,1]<min)or(f[n,1]=min)and(c[n,1]<min1) then
    begin
      min:=f[n,1];min1:=c[n,1];
    end;
    if (f[n,2]<min)or(f[n,2]=min)and(c[n,2]<min1) then
    begin
      min:=f[n,2];min1:=c[n,2];
    end;
    writeln(min1);
  close(input);close(output);
end.