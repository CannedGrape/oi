program expr;
var a:array[1..100001]of int64; b:array[1..100000]of char;
ta,tb,ss,x,y:longint; xx,z:char; fla:boolean;
begin
  assign(input,'expr.in'); reset(input);
  assign(output,'expr.out'); rewrite(output);
  ta:=0; tb:=0; fla:=true; fillchar(a,sizeof(a),0);
  repeat
    if fla then read(xx); fla:=true;
    case xx of
      '0'..'9':begin ss:=0;
        while (ord(xx)>47)and(ord(xx)<58) do
        begin ss:=ss*10+(ord(xx)-48); read(xx); end; fla:=false;
        inc(ta); a[ta]:=ss mod 10000;
      end;
      '+':begin
        while tb>0 do
        begin
          z:=b[tb]; dec(tb); x:=a[ta]; dec(ta); y:=a[ta]; dec(ta);
          if z='*' then x:=x*y else x:=x+y;
          inc(ta); a[ta]:=x mod 10000;
        end;
        inc(tb); b[tb]:=xx;
      end;
      '*':begin
        while (tb>1)and(b[tb]='*') do
        begin
          dec(tb); x:=a[ta]; dec(ta); y:=a[ta]; dec(ta);
          x:=x*y;
          inc(ta); a[ta]:=x mod 10000;
        end;
        inc(tb); b[tb]:=xx;
      end;
    end;
  until eof;
  repeat
    z:=b[tb]; dec(tb); x:=a[ta]; dec(ta); y:=a[ta]; dec(ta);
    if z='*' then x:=x*y else x:=x+y;
    inc(ta); a[ta]:=x mod 10000;
  until tb=0;
  writeln(a[1]);
  close(input); close(output);
end.