{$I-,Q-,R-,S-,V-,X-}
PROGRAM Joshua;
CoNsT
  dline=100000;
  mxn=300000;
VaR
  hs,cnt:array[0..mxn]of longint;
  n,min,tot,m,op,ind:longint;
  ch:char;
Procedure insnum(key,k:longint);
  var
    s,t,md:longint;
  begin
    inc(m,k);
    if k<0 then dec(tot,k);
    s:=0;
    t:=mxn;
    repeat
      md:=(s+t)shr 1;
      if key>=md then inc(cnt[md],k);
      if md=key then break;
      if key>md then s:=md+1 else t:=md-1;
    until false;
    inc(hs[key],k);
  end;
Function fndout(k:longint):longint;
  var
    s,t,md:longint;
  begin
    s:=0;
    t:=mxn;
    repeat
      md:=(s+t)shr 1;
      if k>cnt[md] then
      begin
        dec(k,cnt[md]);
        t:=md-1;
      end else
        if cnt[md]-hs[md]<k then
        begin
          fndout:=md;
          exit;
        end else s:=md+1;
    until false;
  end;
Procedure addnum;
  begin
    inc(op,dline);
    if op<min then inc(tot)
    else insnum(op-ind,1);
  end;
Procedure decmoney;
  var
    i:longint;
  begin
    dec(ind,op);
    if m>0 then
    begin
      i:=fndout(m);
      for i:=i to i+op do
        if (i<=mxn)and(hs[i]>0)and(i+ind<min) then
          insnum(i,-hs[i]);
    end;
  end;
BeGiN
  assign(input,'cashier.in'); reset(input);
  assign(output,'cashier.out');rewrite(output);
  fillchar(hs,sizeof(hs),0);
  fillchar(cnt,sizeof(cnt),0);
  m:=0;
  readln(n,min);
  inc(min,dline);
  ind:=0;
  tot:=0;
  for n:=1 to n do
  begin
    readln(ch,op);
    case ch of
      'I':addnum;
      'A':inc(ind,op);
      'S':decmoney;
      'F':if op>m then writeln(-1)
          else writeln(fndout(op)-dline+ind);
    end;
  end;
  writeln(tot);
  close(input);
  close(output);
EnD.
