"""
Sean Straus
Straus21
3/18/2014
Homework 4 - CSC 131
This Program creates a GUI interface for displaying an address
"""

from Tkinter import*
import tkMessageBox
import cPickle

#Creates GUI interface
class Window(Frame):
	
	def __init__(self,addressbook):
		Frame.__init__(self)
		self.master.title("Address Book")
		self.grid()
		self.addressbook = addressbook
		
		# create main panes
		pane1 = Frame(self)
		pane1.grid(column = 0, row = 0,sticky = W)
		pane2 = Frame(self)
		pane2.grid(column = 0, row = 1,sticky = W)
		pane3 = Frame(self)
		pane3.grid(column = 0, row = 2,sticky = W)
		
		# create data fields
		self.name = StringVar(value = "")
		self.street = StringVar(value = "")
		self.city = StringVar(value = "")
		self.state = StringVar(value = "")
		self.zip = StringVar(value = "")
		
		# create labels for pane1
		self.name_lbl = Label(pane1, text = "Name", width = 6)
		self.name_lbl.grid(column = 0, row = 0)
		self.street_lbl = Label(pane1, text = "Street", width = 6)
		self.street_lbl.grid(column = 0, row = 1)
		
		self.city_lbl = Label(pane2, text = "City", width = 6)
		self.city_lbl.grid(column = 0, row = 2)
		self.state_lbl = Label(pane2, text = "State")
		self.state_lbl.grid(column = 2, row = 2)
		self.zip_lbl = Label(pane2, text = "Zip")
		self.zip_lbl.grid(column = 4, row = 2)
		
		#create entry fields for panes 1 and 2
		self.name_enf = Entry(pane1, width = 40, textvariable = self.name)
		self.name_enf.grid(column = 1, row = 0)
		self.street_enf = Entry(pane1, width = 40, textvariable = self.street)
		self.street_enf.grid(column = 1, row = 1)
		
		self.city_enf = Entry(pane2, textvariable = self.city)
		self.city_enf.grid(column = 1, row = 2)
		self.state_enf = Entry(pane2, width = 4, textvariable = self.state)
		self.state_enf.grid(column = 3, row = 2)
		self.zip_enf = Entry(pane2, width = 5, textvariable = self.zip)
		self.zip_enf.grid(column = 5, row = 2)
		
		#create buttons for pane3
		self.empty1_lbl = Label(pane3, text = "", width = 6)
		self.empty1_lbl.grid(column = 0, row = 0)
		self.add_btn = Button(pane3, text = "Add", command = self.add, state = NORMAL)
		self.add_btn.grid(column = 1, row = 0)
		self.find_btn = Button(pane3, text = "Find", command = self.find, state = NORMAL)
		self.find_btn.grid(column = 2, row = 0)
		self.remove_btn = Button(pane3, text = "Remove", command = self.remove, state = NORMAL)
		self.remove_btn.grid(column = 3, row = 0)
		self.clear_btn = Button(pane3, text = "Clear", command = self.clear, state = NORMAL)
		self.clear_btn.grid(column = 4, row = 0)
		self.save_btn = Button(pane3, text = "Save", command = self.save, state = NORMAL)
		self.save_btn.grid(column = 5, row = 0)
		
	#GUI wrapper for Add Function
	def add(self):
		if self.name.get() in self.addressbook.addresses:
			if tkMessageBox.askyesno("","Address for \"" + self.name.get() + "\"already exists. Do you want to overwrite the old address?") == YES:
				tkMessageBox.showinfo("","Adress for \"" + self.name.get() + "\" has been overwritten")
				self.addressbook.add(Address(self.name.get(),self.street.get(),self.city.get(),self.state.get(),self.zip.get()))
				self.clear()
		else:
			tkMessageBox.showinfo("","Adress for \"" + self.name.get()+ "\" has been added")
			self.addressbook.add(Address(self.name.get(),self.street.get(),self.city.get(),self.state.get(),self.zip.get()))
			self.clear()
		
	#GUI wrapper for Find Function
	def find(self):
		address = self.addressbook.find(self.name.get())
		if address == None:
			tkMessageBox.showinfo("","Adress for \"" + self.name.get()+ "\" could not be found")
		else:
			self.name.set(address.get_name())
			self.street.set(address.get_street())
			self.city.set(address.get_city())
			self.state.set(address.get_state())
			self.zip.set(address.get_zip())
		
	#GUI wrapper for Remove Function
	def remove(self):
		if tkMessageBox.askyesno("","Are you sure you want to delete the address for \"" + self.name.get()+ "\"?") == YES:
			if self.addressbook.remove(self.name.get()) == 1:
				tkMessageBox.showinfo("","Adress has been removed")
				self.clear()
			else:
				tkMessageBox.showinfo("","Adress for \"" + self.name.get()+ "\" does not exist")
				self.clear()
				
		
	#Clears the GUI
	def clear(self):
		self.name.set("")
		self.street.set("")
		self.city.set("")
		self.state.set("")
		self.zip.set("")
		
	#GUI wrapper for Save Function
	def save(self):
		self.addressbook.save()
		tkMessageBox.showinfo("","Adress book has been saved")
		self.clear()
		
#Handles Underlying Address Book component

#Address Class stores and returns information about addresses
class Address(object):

	def __init__(self,name,street,city,state,zip):
		self.name = name
		self.street = street
		self.city = city
		self.state = state
		self.zip = zip
		
	def get_name(self):
		return self.name
		
	def get_street(self):
		return self.street
		
	def get_city(self):
		return self.city
		
	def get_state(self):
		return self.state
		
	def get_zip(self):
		return self.zip

#The AddressBook stores addresses in a dictionary
class AddressBook(object):
	
	def __init__(self,file = None):
		COUNT = 0
		self.addresses = {}
		self.file = file
		if self.file != None:
			self.loadfile = open(self.file, 'r')
			
			while True:
				try:
					address = cPickle.load(self.loadfile)
					self.add(address)
				except EOFError:
					self.loadfile.close()
					break
					
	def add(self,address):
		self.addresses[address.get_name()] = address
		
	def find(self,name):
		try:
			address = self.addresses[name]
		except KeyError:
			address = None
		return address
		
	def remove(self,name):
		try:
			del self.addresses[name]
			output = 1
		except KeyError:
			output = 0
		return output
		
	def save(self):
		if self.file != None:
			self.file = self.file
		elif self.file == None:
			return
		self.savefile = open(self.file, 'w')
		for address in self.addresses.values():
			cPickle.dump(address, self.savefile)
		self.savefile.close()
		
#Instantiate the Addressbook and initialiate GUI
def createAddressBook(x = 1,file = None):
	book = AddressBook(file)
	for i in range(x):
		book.add(Address('Name' + str(i + 1),'Street' + str(i + 1),'City' + str(i + 1),"State",str(10000 + i)))
	return book
	

def main():
	GUI = Window(createAddressBook(2,"addressbook.txt")).mainloop() 
	
main()