program expr1;
  var s:string; jg:longint;
    function js(a,b:longint; f:string):longint;
      begin
        if f='*' then js:=a*b
          else js:=a+b;
      end;
    function val(s:string):longint;
      var x,x2:longint; t,f:longint;
        begin
          t:=0;
          for x:=length(s) downto 1 do
            begin
              f:=1;
              for x2:=(length(s)-x+1) downto 1 do
                f:=f*10;
              f:=f div 10;
              t:=t+(ord(s[x])-48)*f;
            end;
          val:=t;
        end;
    function ex(s:string):longint;
       var x3,x1,x2,jc3,jc1,jc2,k:longint; t:boolean; f:string; s1:string;
         begin
           repeat
             t:=true;
             f:='*';
             s1:='';
             k:=0;
             for x1:=1 to length(s) do
               if s[x1]='*' then break;
             x2:=x1-1;
             while ((s[x2]>='0')and(s[x2]<='9')) do
               begin dec(x2); if x2<1 then begin x2:=x2+1; break; end; end;
             for x3:=x2+1 to x1-1 do
               s1:=s1+s[x3];
             jc1:=0;
             jc1:=val(s1);
             k:=length(s1);
             s1:='';
             x2:=x1+1;
             while ((s[x2]>='0')and(s[x2]<='9')) do
               begin inc(x2); if x2>length(s) then begin x2:=x2-1; break; end; end;
             for x3:=x1+1 to x2-1 do
               s1:=s1+s[x3];
             jc2:=0;
             jc2:=val(s1);
             delete(s,x1-k+1,k);
             delete(s,x1,length(s1)+1);
             x1:=x1-k;
             jc3:=0;
             jc3:=js(jc1,jc2,f);
             insert(str(jc3),s,x1);
             for x1:=1 to length(s) do
               if s[x1]='*' then t:=false;
           until t;
           repeat
             t:=true;
             f:='+';
             s1:='';
             for x1:=1 to length(s) do
               if s[x1]='+' then break;
             for x2:=1 to x1-1 do
               s1:=s1+s[x2];
             jc1:=0;
             jc1:=val(s1);
             s1:='';
             for x3:=x1+1 to length(s) do
               if s[x3]='+' then break;
             for x2:=x1+1 to x3-1 do
               s1:=s1+s[x2];
             jc2:=0;
             jc2:=val(s1);
             delete(s,1, x3);
             ex:=ex+js(jc1,jc2,f);
             for x1:=1 to length(s) do
               if s[x1]='+' then t:=false;
           until t;
         end;
    begin
      assign(input,'expr.in');
      assign(output,'expr.out');
      reset(input);
      rewrite(output);
       read(s);
      jg:=ex(s) mod 1000;
      writeln(jg);
      close(input);
      close(output);
    end.
