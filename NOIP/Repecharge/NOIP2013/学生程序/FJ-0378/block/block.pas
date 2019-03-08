program block;
var height:array[-10..110000]of longint;
      i,j,n,k,tmp,ans,vl,vr,lasthei,lastlowl,lastlowr:longint;
	  flag,pass,ac:boolean;
	  
function max(va,vb:longint):longint;
begin
     if (va>vb) then exit(va)
		 else exit(vb);
end;
	  
begin
     assign(input,'block.in');reset(input);
	 assign(output,'block.out');rewrite(output);
	 ans:=0;
	 readln(n);
	 for i:=1 to n do
		 read(height[i]);
     //---------------------------------------
	 ac:=true;
	 while ac=true do
	 begin
	 pass:=false;
	 lastlowl:=height[1];
	 lasthei:=0;
	 vl:=1;
	 for i:=1 to n do
		 begin
	         if (height[i]>=lasthei) and (pass=false) then
				begin
			         lasthei:=height[i];
			     end
			 else if pass=false then 
				    begin
				     pass:=true;
			         lastlowr:=height[i];
	                 end
			   else if height[i]<=lastlowr then lastlowr:=height[i]
				    else begin
						     //writeln('changed');
						     vr:=i-1;
					         tmp:=max(lastlowl,lastlowr);
						     if lastlowl=lasthei then tmp:=lastlowr;
							 if lastlowr=lasthei then tmp:=lastlowl;
							 if (lastlowl=lasthei) and (lastlowr=lasthei) then
								 tmp:=0;
						     inc(ans,lasthei-tmp);
					         for j:=vl to vr do
								 if height[j]>tmp then height[j]:=tmp;
					         lastlowl:=height[i-1];
							 vl:=i-1;
					         pass:=false;
					         lasthei:=height[i];
				    end;
			 {writeln(pass);
			 writeln(lastlowl,' ',lasthei,' ',lastlowr);}
	     end;
	     vr:=n;
		 lastlowr:=height[n];
		 tmp:=max(lastlowl,lastlowr);
		 if lastlowl=lasthei then tmp:=lastlowr;
		 if lastlowr=lasthei then tmp:=lastlowl;
		if (lastlowl=lasthei) and (lastlowr=lasthei) then
		tmp:=0;
		 inc(ans,lasthei-tmp);
		 for j:=vl to vr do
				 if height[j]>tmp then height[j]:=tmp;	
    //--------------------------------
		 {for i:=1 to n do
			 write(height[i],' ');
		 writeln;}
		 flag:=false;
		 for i:=1 to n do
			 if height[i]>0 then flag:=true;
		 if flag=false then break;
	 end;
	 //------------------------------------------------
	 writeln(ans);
     close(input);
	 close(output);
end.