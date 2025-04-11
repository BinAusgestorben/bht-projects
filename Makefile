Mantel: Schuhe Handy Pullover
	@echo Mantel anziehen
	@touch $@

Schuhe: Hose Struempfe
	@echo Schuhe anziehen
	@touch $@

Handy: Hose
	@echo Handy einstecken
	@touch $@

Pullover: Hemd
	@echo Pullover anziehen
	@touch $@

Hose: Unterhose Hemd
	@echo Hose anziehen
	@touch $@

Hemd: Unterhemd
	@echo Hemd anziehen
	@touch $@

Unterhemd:
	@echo Unterhemd anziehen
	@touch $@

Unterhose:
	@echo Unterhose anziehen
	@touch $@

Struempfe:
	@echo Strümpfe anziehen
	@touch $@

Nackt: 
	rm -f Mantel Handy Schuhe Pullover Hose Hemd Unterhemd Struempfe Unterhose
