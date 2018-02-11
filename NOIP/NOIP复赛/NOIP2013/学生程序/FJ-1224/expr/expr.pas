var s,x,y:string;
    i,j,k,l,ls,lx,ans:longint;
    a:array[1..100000]of longint;
    b:array[1..100000]of char;
begin
  assign(input,'expr.in');reset(input);
  assign(output,'expr.out');rewrite(output);
  readln(s);s:=s+'+';
  ls:=length(s);
  j:=0;k:=0;l:=0;
  for i:=1 to ls do
    if (s[i]='+')or(s[i]='*')then
      begin
        x:='';
        x:=copy(s,l+1,i-l-1);
        inc(j);
        val(x,a[j]);
        inc(k);
        b[k]:=s[i];
        l:=i;
      end;
  for i:=1 to k do
    if b[i]='*' then
      begin
        a[i+1]:=a[i]*a[i+1];
        a[i]:=0;
      end;
  ans:=0;
  for i:=1 to j do
    ans:=ans+a[i];
  x:='';
  str(ans,x);lx:=length(x);
  if lx<=4 then writeln(x)
  else begin
    y:=copy(x,lx-3,4);
    while y[1]='0' do delete(y,1,1);
    writeln(y);
  end;
  close(input);close(output);
end.
