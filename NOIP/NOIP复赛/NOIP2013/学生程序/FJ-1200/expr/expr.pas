program expr;
var
  i,j,k,l,n,m:longint;
  s,s1,z:ansistring;
  a:array[1..100000]of ansistring;
begin
  assign(input,'expr.in');
  reset(input);
  assign(output,'expr.out');
  rewrite(output);
  readln(s);
  if s[1]in['0'..'9']then insert('+',s,1);
  repeat

    inc(i);
    if (s[i] in['0'..'9'])and(not(s[i+1]in ['0'..'9','*']))then
    begin
    inc(j);
    a[j]:=copy(s,1,i);
    delete(s,1,i);
    i:=0;
  end;
   m:=1;
  until i>=length(s);
  for i:=1 to j do
  begin
    delete(a[i],1,1);
    if pos('*',a[i])=0 then begin
    val(a[i],n,l);
    k:=k+n;
    end else begin
      while pos('*',a[i])<>0 do
      begin
        s1:=copy(a[i],1,pos('*',a[i])-1);
        val(s1,n,l);
        delete(a[i],1,pos('*',a[i]));
        m:=m*n;
      end;
      val(a[i],n,l);
      k:=k+m*n;
    end;
  end;
  str(k,z);
  if length(z)<=4 then write(z) else
  begin
  s1:=copy(z,length(z)-3,4);
  while s1[1]='0' do
  delete(s1,1,1);
  if s1='' then write('0')else write(s1);
  end;
  close(input);
  close(output);
end.
