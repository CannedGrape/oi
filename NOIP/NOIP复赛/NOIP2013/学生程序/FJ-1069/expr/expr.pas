program expr;
type lclc=record
       h:longint;
       t:longint;
     end;
var
  n1,n2,ans:longint;
  i,j,n,b,k:longint;
  s:ansistring;
  total:qword;
  s1:string;
  num:array[1..200000]of longint;
  re:array[1..200000]of boolean;
  lc:array[1..200000]of lclc;
  lj:array[1..200000]of integer;
  num2:array[1..100000]of longint;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(s);
  s:=s+' ';
  n:=0;
  fillchar(re,sizeof(re),false);
  fillchar(num,sizeof(num),0);
  for i:=1 to 20000 do num2[i]:=1;
  s1:=' ';
  for i:=1 to length(s) do
  begin
    b:=ord(s[i]);
    if (b>=48)and(b<=57) then
      s1:=s1+s[i] else
    begin
      inc(n);
      val(s1,num[n]);
      s1:=' ';
      if (s[i]='*')then re[n]:=true;
    end;
  end;
  j:=0;
  i:=0;
  n1:=0;
  n2:=0;
  repeat
    inc(i);
    if re[i] then
      begin
        inc(j);
        lc[j].h:=i;
        while re[i] do
          inc(i);
        lc[j].t:=i;
      end else begin
                 inc(n1);
                 lj[n1]:=num[i];
               end;
  until i>=n;
  for i:=1 to j do
    begin
      inc(n2);
      for k:=lc[i].h to lc[i].t do
        begin
          num2[n2]:=num2[n2]*num[k];
          if num2[n2]>10000 then num2[n2]:=num2[n2]mod 10000;
        end;
    end;
  for i:=1 to n1 do
    total:=total+lj[i];
  for i:=1 to n2 do
    total:=total+num2[i];
  writeln(total mod 10000);
  close(input);
  close(output);
end.
