var
  s:ansistring;
  x:string;
  fi,ans,tim1,tim2,sum,fi1,fi2:longint;
begin
  assign(input,'expr.in');
  assign(output,'expr.out');
  reset(input);
  rewrite(output);
  readln(s);
  s:='F'+s+'E';
  repeat
    fi:=pos('*',s);
    if fi>0 then begin
      fi1:=fi-1; fi2:=fi+1;
      while (copy(s,fi1,1)<>'+') and (copy(s,fi1,1)<>'*') and (copy(s,fi1,1)<>'F') do dec(fi1);
      while (copy(s,fi2,1)<>'+') and (copy(s,fi2,1)<>'*') and (copy(s,fi2,1)<>'E') do inc(fi2);
      val(copy(s,fi1+1,fi-fi1-1),tim1);
      if tim1>10000 then tim1:=tim1 mod 10000;
      if tim2>10000 then tim2:=tim2 mod 10000;
      val(copy(s,fi+1,fi2-fi-1),tim2);
      str(tim1*tim2,x);
      s:=copy(s,1,fi1)+x+copy(s,fi2,length(s)-fi2+1);
    end;
  until fi=0;
  delete(s,1,1); delete(s,length(s),1);
  repeat
    fi:=pos('+',s);
    val(copy(s,1,fi-1),sum);
    ans:=(ans+(sum mod 100000)) mod 10000;
    delete(s,1,fi);
  until fi=0;
  val(copy(s,1,length(s)),sum);
  ans:=(ans+(sum mod 100000)) mod 10000;
  writeln(ans);
  close(input);
  close(output);
end.
