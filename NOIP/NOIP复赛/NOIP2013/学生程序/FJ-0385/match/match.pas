program match;
var i,j,n,z,t,jh:longint;
    a,b:array[-1..100001] of longint;

begin
  assign(input,'match.in');
  assign(output,'match.out');
  reset(input);
  rewrite(output);
    readln(n);
    jh:=0;
    z:=0;
    t:=0;
    for i:=1 to n do read(a[i]);
    for i:= 1 to n do read(b[i]);
    for i:=1 to n do
      for j:=i+1 to n do
      begin
        z:= (a[i]-b[i])*(a[i]-b[i]);
        if z>((a[i]-b[j])*(a[i]-b[j]))
          then
          begin
            t:=b[i];
            b[i]:=b[j];
            b[j]:=t;
            jh:=jh+1;
          end;
      end;



    write(jh);

  close(input);
  close(output);

end.
