var jc,jj:array[1..50001]of string;
    s:ansistring;ans1:string;
    i,j,k,t,lj,lc,x:longint;bj,bc,bo:boolean;ans:int64;
begin
  assign(input,'expr.in');
  reset(input);
  assign(output,'expr.out');
  rewrite(output);
  bj:=false;bc:=false;
  readln(s);
  for i:=1 to length(s) do
  begin
    if (bj)and(bc) then break;
    if s[i]='+' then begin bj:=true;lj:=i;end;
    if s[i]='*' then begin bc:=true;lc:=i;end;
  end;
  k:=0;
  if (bj) and(not bc) then
  begin
  t:=1;ans:=0;
  for i:=1 to lj do
  begin
    if s[i] in ['0'..'9'] then jj[t]:=jj[t]+s[i];
    if s[i]='+' then
    begin
      val(jj[t],k);
      inc(t);
      ans:=ans+k;
    end;
  end;
  for i:=lj+1 to length(s) do jj[t]:=jj[t]+s[i];
  val(jj[t],k);ans:=ans+k;
  end
  else if (bc)and(not bj) then
  begin
    ans:=1;
    t:=1;
    for i:=1 to lc do
    begin
    if s[i] in ['0'..'9'] then jc[t]:=jc[t]+s[i];
    if s[i]='*' then
    begin
      val(jc[t],k);
      inc(t);
      ans:=ans*k;
    end;
  end;
  for i:=lc+1 to length(s) do jc[t]:=jc[t]+s[i];
  val(jc[t],k);ans:=ans*k;
  end;
  str(ans,ans1);bo:=false;
  if length(ans1)>4 then
  begin
    x:=length(ans1)-3;
    while x<=length(ans1) do
    begin
      if ans1[x]<>'0' then begin write(ans1[x]);bo:=true;end else
      if bo then write(ans1[x]);inc(x);
    end;
  end
  else write(ans1);
  close(input);
  close(output);
end.
