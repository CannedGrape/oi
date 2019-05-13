program tortoise(input,output);
  const
    maxcount=40;
    maxn=350;
  var
    f:array[-1..maxcount,-1..maxcount,-1..maxcount,-1..maxcount] of longint;
    score:array[1..maxn] of longint;
    a:array[1..4] of longint;
    n,m,i,j,k,l,step,x:longint;
  begin
    assign(input,'tortoise.in');reset(input);
    assign(output,'tortoise.out');rewrite(output);
    readln(n,m);
    for i:=1 to n do
      read(score[i]);
    readln;
    fillchar(a,sizeof(a),0);
    for i:=1 to m do begin
      read(x);
      inc(a[x]);
    end;
    fillchar(f,sizeof(f),0);
    for i:=0 to a[1] do
      for j:=0 to a[2] do
        for k:=0 to a[3] do
          for l:=0 to a[4] do begin
            step:=i+j*2+k*3+l*4+1;
            if f[i,j,k,l]<f[i-1,j,k,l] then
              f[i,j,k,l]:=f[i-1,j,k,l];
            if f[i,j,k,l]<f[i,j-1,k,l] then
              f[i,j,k,l]:=f[i,j-1,k,l];
            if f[i,j,k,l]<f[i,j,k-1,l] then
              f[i,j,k,l]:=f[i,j,k-1,l];
            if f[i,j,k,l]<f[i,j,k,l-1] then
              f[i,j,k,l]:=f[i,j,k,l-1];
            inc(f[i,j,k,l],score[step]);
          end;
    writeln(f[a[1],a[2],a[3],a[4]]);
    close(input);close(output);
  end.