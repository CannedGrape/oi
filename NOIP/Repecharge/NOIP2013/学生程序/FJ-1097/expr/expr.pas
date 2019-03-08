type sb=record
       l:int64;
       c:char;     end;
var
   s:string;
   pl:array [1..100] of sb;
   a:integer;
   i,j,num:integer;
   o:int64;
begin
     assign(input,'expr.in');
     reset(input);
     assign(output,'expr.out');
     rewrite(output);
        readln(s); a:=1;  o:=1;  num:=1;
        for i:=1 to 100 do pl[i].l:=0;

        for i:=1 to length(s) do
            begin
              if (s[i]='+') or (s[i]='*') then
                  begin
                   for j:=i-1 downto a do
                      begin
                         pl[num].l:=pl[num].l+(ord(s[j])-ord('0'))*o;
                         o:=o*10;
                      end;
                   o:=1;
                   pl[num].c:=s[i];
                   inc(num);
                   a:=i+1;
                  end;
            end;
        for i:=length(s) downto a do
                    begin
                        pl[num].l:=pl[num].l+(ord(s[j])-ord('0'))*o;
                        o:=o*10;
                    end;

        i:=1;
        while i<=num do
             begin
                if pl[i].c='*' then
                    begin
                     pl[i].l:=pl[i].l*pl[i+1].l;
                     num:=num-1;
                     for j:=i+1 to num do
                       begin
                         pl[j].l:=pl[j+1].l;
                         pl[j-1].c:=pl[j].c;
                       end;
                     pl[j].c:=pl[j+1].c;
                    end
                else inc(i);
             end;

        for i:=num-1 downto 1 do pl[i].l:=pl[i].l+pl[i+1].l;
        writeln((pl[1].l+1) mod 10000);
     close(input);
     close(output);
end.
