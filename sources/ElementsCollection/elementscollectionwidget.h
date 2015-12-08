/*
        Copyright 2006-2015 The QElectroTech Team
        This file is part of QElectroTech.

        QElectroTech is free software: you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation, either version 2 of the License, or
        (at your option) any later version.

        QElectroTech is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with QElectroTech.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef ELEMENTSCOLLECTIONWIDGET_H
#define ELEMENTSCOLLECTIONWIDGET_H

#include <QWidget>
#include <QModelIndex>

class ElementsCollectionModel;
class QTreeView;
class QVBoxLayout;
class QMenu;
class QLineEdit;
class ElementCollectionItem;

/**
 * @brief The ElementsCollectionWidget class
 * This widget embedd a tree view that display the element collection (common, custom, embedded)
 * and all action needed to use this widget.
 * This is the element collection widget used in the diagram editor.
 */
class ElementsCollectionWidget : public QWidget
{
        Q_OBJECT

    public:
        ElementsCollectionWidget(QWidget *parent = nullptr);

        void expandFirstItems();
        ElementsCollectionModel *model() const;

	private:
		void setUpAction();
		void setUpWidget();
		void setUpConnection();
		void customContextMenu(const QPoint &point);
		void openDir();
		void editElement();
		void deleteElement();
		void deleteDirectory();
		void editDirectory();
		void newDirectory();
		void newElement();
		void reload();
		void search(const QString &text);
		void hideCollection(bool hide = true);
		void hideItem(bool hide, const QModelIndex &index = QModelIndex(), bool recursive = true);
		void showAndExpandItem (const QModelIndex &index, bool recursive = true);

    private:
        ElementsCollectionModel *m_model;
		QLineEdit *m_search_field;
        QTreeView *m_tree_view;
        QVBoxLayout *m_main_vlayout;
		QMenu *m_context_menu;
		ElementCollectionItem *m_item_at_context_menu;

		QAction *m_open_dir,
				*m_edit_element,
				*m_delete_element,
				*m_delete_dir,
				*m_reload,
				*m_edit_dir,
				*m_new_directory,
				*m_new_element;
};

#endif // ELEMENTSCOLLECTIONWIDGET_H