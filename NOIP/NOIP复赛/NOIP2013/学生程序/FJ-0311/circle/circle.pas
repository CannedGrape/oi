Program circle;
Var
  n,m,x,temp:longint;
  a:array[0..1000000] of longint;
  ans:longint;
  i,j:longint;
  k,mik:qword;

Begin
  assign(input,'circle.in');reset(input);
  assign(output,'circle.out');rewrite(output);
  readln(n,m,k,x);

  fillchar(a,sizeof(a),0);
  mik:=1;
  ans:=m;

  for i:=0 to n do a[i]:=1;
  while k<>0 do begin
    if mik>100000000000000000 then mik:=mik mod n;
    mik:=mik*10;
    dec(k);
  end;

  mik:=mik mod n;



  for i:=1 to mik do begin
    ans:=ans-m;
    if ans<0 then ans:=n-1-(abs(ans+1));
  end;

  a[m]:=ans;
  for i:=m+1 to n do begin
    inc(ans);
    if ans=n then ans:=0;
    a[i]:=ans;
    end;

  for i:=0 to m-1 do begin
    a[i]:=ans;
    inc(ans);
    if ans=n then ans:=0
  end;

  writeln(a[x]);
  close(input);close(output);
End.
