program ex2;
  var s:string;
      js1,tot,cs1,cs2,code,num,l,i,head:longint;
      z:array[-10..30000] of string;
  begin
  assign(input,'expr.in');
    reset(input);
    assign(output,'expr.out');
    rewrite(output);
  readln(s);
  l:=length(s);
  head:=1;
  for i:=1 to l do
    begin
    if (s[i]='+') or (s[i]='*') then
      begin
      inc(head);
      z[head]:=s[i];
      inc(head);
      end
    else
      begin
      z[head]:=z[head]+s[i];
      if ((s[i+1]='*') or (s[i+1]='+') or (i=l) ) and (z[head-1]='*') then
      begin
      val(z[head],cs1,code);
      cs1:=cs1 mod 10000;
      val(z[head-2],cs2,code);
      cs2:=cs2 mod 10000;
      num:=cs1*cs2;
      num:=num mod 10000;
      str(num,z[head-2]);
      head:=head-2;
      z[head+1]:='';
      z[head+2]:='';
      end;
      end;
    end;
  for i:=1 to head do
    if i mod 2=1 then
      begin
      val(z[i],js1,code);
      js1:=js1 mod 10000;
      tot:=tot+js1;
      tot:=tot mod 10000;
      end;
  write(tot);
  close(input);
  close(output);
  end.

