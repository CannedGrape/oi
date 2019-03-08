var
  s:string;
  ans:longint;
procedure fenli(s:string);
var
  anss,s2,s3,s4,sa,sb:string;
  i,j,a,b,c,d:int64;
begin
  //writeln(s);
  if (pos('+',s)=0) and (pos('*',s)=0) then
  begin
    val(s,c);
    ans:=ans+c;
    str(ans,anss);
    anss:=copy(anss,length(anss)-4+1,length(anss));
    val(anss,ans); //writeln(s);
  end else
  begin
  if pos('+',s)>0 then
  begin
    {s2:=s;delete(s,pos('+',s),length(s));fenli(s);
    delete(s2,1,pos('+',s));fenli(s);}
      s2:=s;
  i:=pos('+',s);
  s2:=copy(s,i+1,length(s));
  sa:=copy(s,1,i-1);
  sb:=copy(s,i+1,length(s));
  fenli(sa);fenli(sb);
  end else
  begin
    i:=pos('*',s); c:=1;//writeln(i);
    while i<>0 do
    begin
      s2:=copy(s,i+1,length(s));
      j:=pos('*',s2);
      if j=0 then
      begin
        s3:=copy(s,1,i-1);
        s4:=copy(s,i+1,length(s));
        val(s3,a);val(s4,b);
        str(a*b,s3);
        s3:=copy(s3,length(s3)-4+1,length(s3));
        val(s3,d);
        c:=c*d;
        str(c,s3);
        s3:=copy(s3,length(s3)-4+1,length(s3));
        val(s3,c);
        i:=0;
       // writeln(c);
      end else
      begin
        s3:=copy(s,1,i-1);
        s4:=copy(s,i+1,j-1);
        val(s3,a);val(s4,b);
        str(a*b,s3);
        s3:=copy(s3,length(s3)-4+1,length(s3));
        val(s3,d);
        c:=c*d;
        str(c,s3);
        s3:=copy(s3,length(s3)-4+1,length(s3));
        val(s3,c);
        i:=pos('*',s);
        delete(s,1,j);
      end;
    end;
    str(c+ans,anss);
    s3:=copy(anss,length(anss)-4+1,length(anss));
    val(anss,ans);
   // writeln(ans);
  end;
  end;
end;
begin
 assign(input,'expr.in');reset(input);
  assign(output,'expr.out');rewrite(output);
  readln(s);
  fenli(s);
  writeln(ans);
  close(input);close(output);
end.
