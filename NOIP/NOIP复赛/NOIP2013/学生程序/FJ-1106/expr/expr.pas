var s1,s2,s5,s:ansistring;
    s6:string;
    w,left,right,wrong,ans:longint;
    v1,v2,value:int64;
procedure cha(var ss:ansistring;wei:longint;sss:string);
var s3,s4:string;
begin
  s3:=copy(ss,1,wei-1);
  s4:=copy(ss,wei,length(ss)-wei+1);
  ss:=s3+sss+s4;
end;
begin
  assign(input,'expr.in');
  reset(input);
  assign(output,'expr.out');
  rewrite(output);
  readln(s);
  while pos('*',s)<>0 do
  begin
    w:=pos('*',s);
    left:=w-1;
    right:=w+1;
    while (s[left]<>'*')and(s[left]<>'+') do begin
      dec(left);
      if left=0 then break;
    end;
    while (s[right]<>'+')and(s[right]<>'*') do begin
      inc(right);
      if right=length(s)+1 then break;
    end;
    s1:=copy(s,left+1,w-left-1);
	s2:=copy(s,w+1,right-w-1);
	val(s1,v1,wrong);
	val(s2,v2,wrong);
	value:=v1*v2;
	str(value,s5);
        delete(s,left+1,right-left-1);
	cha(s,left+1,s5);
  end;
  while pos('+',s)<>0 do
  begin
    w:=pos('+',s);
    left:=w-1;
    right:=w+1;
    while (s[left]<>'*')and(s[left]<>'+') do begin
      dec(left);
      if left=0 then break;
    end;
    while (s[right]<>'+')and(s[right]<>'*') do begin
      inc(right);
      if right=length(s)+1 then break;
    end;
    s1:=copy(s,left+1,w-left-1);
	s2:=copy(s,w+1,right-w-1);
	val(s1,v1,wrong);
	val(s2,v2,wrong);
	value:=v1+v2;
	str(value,s5);
        delete(s,left+1,right-left-1);
	cha(s,left+1,s5);
  end;
  if length(s)<=4 then begin
    val(s,ans,wrong);
    writeln(ans);
  end else begin
    s6:=copy(s,length(s)-3,4);
    val(s6,ans,wrong);
    writeln(ans);
  end;
  close(input);
  close(output);
end.
